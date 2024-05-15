//  Alai Miranda Blanco Lascurain
//  Catalina Fullana Mora

package simulator.launcher;

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

import org.apache.commons.cli.CommandLine;
import org.apache.commons.cli.CommandLineParser;
import org.apache.commons.cli.DefaultParser;
import org.apache.commons.cli.HelpFormatter;
import org.apache.commons.cli.Option;
import org.apache.commons.cli.Options;
import org.apache.commons.cli.ParseException;
import org.json.JSONObject;
import org.json.JSONTokener;

import simulator.Simulator;
import simulator.control.Controller;
import simulator.factories.*;
import simulator.misc.Utils;
import simulator.model.animals.*;
import simulator.model.regions.Region;
import simulator.view.MainWindow;

import javax.swing.*;


public class Main {

    private enum ExecMode {
        BATCH("batch", "Batch mode"), GUI("gui", "Graphical User Interface mode");

        private String _tag;
        private String _desc;

        private ExecMode(String modeTag, String modeDesc) {
            _tag = modeTag;
            _desc = modeDesc;
        }

        public String get_tag() {
            return _tag;
        }

        public String get_desc() {
            return _desc;
        }
    }

    private final static Double _default_time = 10.0; // in seconds
    public final static Double _default_dt = 0.003;

    private static Double _time = null;
    private static Double _dt = null;
    private static String _in_file = null;
    private static String _out_file = null;

    private static ExecMode _mode = ExecMode.GUI;

    private static Factory<Animal> animalFactory;
    public static Factory<Region> regionFactory;
    private static boolean sv = false;
    private static int cols;
    private static int rows;
    private static int width;
    private static int height;

    private final static int _default_cols=20;
    private final static int _default_rows=15;
    private final static int _default_width=800;
    private final static int _default_height=600;



    private static void parse_args(String[] args) {

        Options cmdLineOptions = build_options();

        CommandLineParser parser = new DefaultParser();
        try {
            CommandLine line = parser.parse(cmdLineOptions, args);
            parse_help_option(line, cmdLineOptions);
            parse_mode_option(line);
            parse_in_file_option(line);
            parse_out_file_option(line);

            parse_time_option(line);
            parse_sv_option(line);
            parse_dt_option(line);

            String[] remaining = line.getArgs();

            if (remaining.length > 0) {
                String error = "Illegal arguments:";
                for (String o : remaining)
                    error += (" " + o);
                throw new ParseException(error);
            }

        } catch (ParseException e) {
            System.err.println(e.getLocalizedMessage());
            System.exit(1);
        }

    }

    private static Options build_options() {
        Options cmdLineOptions = new Options();

        cmdLineOptions.addOption(Option.builder("dt").longOpt("delta-time").hasArg()
                .desc("A double representing actual time, in\n seconds, " +
                        "per simulation step. Default value: 0.03").build());

        // help
        cmdLineOptions.addOption(Option.builder("h").longOpt("help")
                .desc("Print this message.").build());

        // input file
        cmdLineOptions.addOption(Option.builder("i").longOpt("input").hasArg()
                .desc("A configuration file (optional in GUI mode)").build());

        // mode
        cmdLineOptions.addOption(Option.builder("m").longOpt("mode").hasArg()
                .desc("Execution Mode. Possible values: 'batch' (Batch\n" +
                        "mode), 'gui' (Graphical User Interface mode).\n" +
                        "Default value: 'gui'.").build());

        // output
        cmdLineOptions.addOption(Option.builder("o").longOpt("output").hasArg()
                .desc("Output file, where output is written (only for BATCH mode).").build());

        //simple viewer
        cmdLineOptions.addOption(Option.builder("sv").longOpt("simple-viewer")
                .desc("Show the viewer window in console mode.").build());


        // steps
        cmdLineOptions.addOption(Option.builder("t").longOpt("time").hasArg()
                .desc("An real number representing the total simulation " +
                        "time in seconds. Default value: " + _default_time + ". (only for BATCH mode).").build());


        return cmdLineOptions;
    }

    private static void parse_help_option(CommandLine line, Options cmdLineOptions) {
        if (line.hasOption("h")) {
            HelpFormatter formatter = new HelpFormatter();
            formatter.printHelp(Main.class.getCanonicalName(), cmdLineOptions, true);
            System.exit(0);
        }
    }

    private static void parse_in_file_option(CommandLine line) throws ParseException {
        _in_file = line.getOptionValue("i");
        if (_mode == ExecMode.BATCH && _in_file == null) {
            throw new ParseException("In batch mode an input configuration file is required");
        }
    }

    private static void parse_out_file_option(CommandLine line) throws ParseException {
        _out_file = line.getOptionValue("o");
        if (_mode == ExecMode.BATCH && _out_file == null) {
            throw new ParseException("In batch mode an output configuration file is required");
        }
    }

    private static void parse_sv_option(CommandLine line) throws ParseException {
        if (_mode == ExecMode.BATCH && line.hasOption("-sv")) {
            sv = true;
        }
    }

    private static void parse_mode_option(CommandLine line) throws ParseException {
        if (line.hasOption("m")) {
            String opt=line.getOptionValue("m");
            if(Objects.equals(opt, "gui"))
                _mode = ExecMode.GUI;
            else if (Objects.equals(opt, "BATCH")) {
                _mode = ExecMode.BATCH;
            }
        }
    }

    private static void parse_time_option(CommandLine line) throws ParseException {
        String t = line.getOptionValue("t", _default_time.toString());
        try {
            _time = Double.parseDouble(t);
            assert (_time >= 0);
        } catch (Exception e) {
            throw new ParseException("Invalid value for time: " + t);
        }
    }

    private static void parse_dt_option(CommandLine line) throws ParseException {
        String dt = line.getOptionValue("dt", _default_dt.toString());
        try {
            _dt = Double.parseDouble(dt);
            assert (_dt >= 0);
        } catch (Exception e) {
            throw new ParseException("Invalid value for dt: " + dt);
        }
    }

    private static void init_factories() {

        List<Builder<SelectionStrategy>> selection_strategy_builders = new ArrayList<>();
        selection_strategy_builders.add(new SelectFirstBuilder());
        selection_strategy_builders.add(new SelectClosestBuilder());
        selection_strategy_builders.add(new SelectYoungestBuilder());
        Factory<SelectionStrategy> selection_strategy_factory = new BuilderBasedFactory<SelectionStrategy>(selection_strategy_builders);
        List<Builder<Animal>> animal_builders = new ArrayList<>();

        animal_builders.add(new WolfBuilder(selection_strategy_factory));
        animal_builders.add(new SheepBuilder(selection_strategy_factory));
        animal_builders.add(new CowBuilder(selection_strategy_factory));

        animalFactory = new BuilderBasedFactory<Animal>(animal_builders);

        List<Builder<Region>> region_builders = new ArrayList<>();
        region_builders.add(new DefaultRegionBuilder());
        region_builders.add(new DynamicSupplyRegionBuilder());
        region_builders.add(new NewRegionBuilder());
        regionFactory = new BuilderBasedFactory<>(region_builders);

    }

    private static JSONObject load_JSON_file(InputStream in) {
        return new JSONObject(new JSONTokener(in));
    }

    private static void start_batch_mode() throws Exception {
        try {
            FileInputStream is = new FileInputStream(_in_file);
            // (1) cargar el archivo de entrada en un JSONObject;
            JSONObject archivo_entrada = load_JSON_file(is);
            // (2) crear el archivo de salida
            OutputStream os = new FileOutputStream(_out_file);
            // (3) crear una instancia de Simulator pasando a su constructora la información que necesita;
            get_info_simulator(archivo_entrada);
            Simulator sim = new Simulator(cols, rows, width, height, animalFactory, regionFactory);
            // (4) crear una instancia de Controller pasandole el simulador;
            Controller cont = new Controller(sim);
            // (5) llamar a load_data pasandole el JSONObject de la entrada
            cont.load_data(archivo_entrada);
            // (6) run
            cont.run(_time, _dt, sv, os);
            // (7) cerrar archivo
            os.close();
        } catch (FileNotFoundException e){
            System.err.println("No se ha encontrado el archivo de entrada\n"+ e);
        }
    }

    private static void get_info_simulator(JSONObject info) {
            cols = info.getInt("cols");
            rows = info.getInt("rows");
            height = info.getInt("height");
            width = info.getInt("width");
    }

    private static void start_GUI_mode() throws Exception {
        Controller cont;
        if(_in_file!=null) {
            JSONObject jo = inputFile();
            Simulator sim = new Simulator(cols, rows, width, height, animalFactory, regionFactory);
            cont = new Controller(sim);
            cont.load_data(jo);
        } else{
            Simulator sim = new Simulator( _default_cols, _default_rows, _default_width, _default_height,
                    animalFactory, regionFactory);
            cont = new Controller(sim);
        }

        SwingUtilities.invokeAndWait(() -> new MainWindow(cont));
        //throw new UnsupportedOperationException("GUI mode is not ready yet ...");
    }
    static private JSONObject inputFile() throws FileNotFoundException {
        FileInputStream is = new FileInputStream(_in_file);
        JSONObject archivo_entrada = load_JSON_file(is);
        get_info_simulator(archivo_entrada);
        return archivo_entrada;
    }

    private static void start(String[] args) throws Exception {
        init_factories();
        parse_args(args);
        switch (_mode) {
            case BATCH:
                start_batch_mode();
                break;
            case GUI:
                start_GUI_mode();
                break;
        }
    }


    public static void main (String[] args) {
        Utils._rand.setSeed(2147483647l);
        try {
            start(args);
        } catch (Exception e) {
            System.err.println("Something went wrong ...");
            System.err.println();
            e.printStackTrace();
        }
    }


}
