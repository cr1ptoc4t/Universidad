package simulator.view;

import org.json.JSONObject;
import org.json.JSONTokener;
import simulator.control.Controller;
import simulator.launcher.Main;
import simulator.misc.Utils;

import javax.swing.*;
import java.awt.*;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;

import static java.lang.Double.parseDouble;

//import static simulator.launcher.Main.load_JSON_file;

class ControlPanel extends JPanel {
    private Controller _ctrl;
    private ChangeRegionsDialog _changeRegionsDialog;
    private JToolBar _toolaBar;
    private JFileChooser _fc;
    private boolean _stopped = true; // utilizado en los botones de run/stop
    private JButton _quitButton;
    private JButton _explorer, _run,_regions_button, _viewer_button, _stop;
    private JSpinner _steps;
    private JTextField _delta_time;

    ControlPanel(Controller ctrl) {
        _ctrl = ctrl;
        initGUI();
    }
    private void createButtonsInToolBar(){
        _toolaBar.addSeparator();
        _viewer_button = createButtonInToolBar("Viewer", "resources/icons/viewer.png");
        _regions_button = createButtonInToolBar("Regions", "resources/icons/regions.png");

        _toolaBar.addSeparator();
        _run = createButtonInToolBar( "Run", "resources/icons/run.png");
        _stop =createButtonInToolBar("Stop", "resources/icons/stop.png");

        _toolaBar.addSeparator();
    }

    private void initGUI() {
        setLayout(new BorderLayout());
        _toolaBar = new JToolBar();
        add(_toolaBar, BorderLayout.PAGE_START);


        fileChooserButton();
        createButtonsInToolBar();
        stepsSpinner();
        _toolaBar.addSeparator();
        deltaTimeBox();
        actionListeners();

        //Quit button
        _toolaBar.add(Box.createGlue());
        _toolaBar.addSeparator();
        _quitButton = new JButton();
        _quitButton.setToolTipText("Quit");
        _quitButton.setIcon(new ImageIcon("resources/icons/exit.png"));
        _quitButton.addActionListener((e) -> ViewUtils.quit(this));
        _toolaBar.add(_quitButton);

        _changeRegionsDialog = new ChangeRegionsDialog(_ctrl, ViewUtils.getWindow(this.getParent()));
    }

    private void stepsSpinner(){
        _toolaBar.add(Box.createGlue());
        _toolaBar.add(new JLabel("Steps:"));

        _steps = new JSpinner();
        _steps.setToolTipText("steps");
        _steps.setPreferredSize(new Dimension(75,15));
        _steps.setValue(10000);
        _toolaBar.add(_steps);
    }

    private void deltaTimeBox(){
        _toolaBar.add(Box.createGlue());
        _toolaBar.add(new JLabel("Delta-Time:"));

        _delta_time = new JTextField();
        _delta_time.setToolTipText("Delta-time");
        _delta_time.setPreferredSize(new Dimension(75,10));
        _delta_time.setText(Main._default_dt.toString());

        _toolaBar.add(_delta_time);
    }

    private void fileChooserButton() {
        _fc = new JFileChooser();
        _fc.setCurrentDirectory(new File(System.getProperty("user.dir") + "/resources/examples"));

        _explorer = new JButton();
        _explorer.setToolTipText("Explorer");
        _explorer.setIcon(new ImageIcon("resources/icons/open.png"));

        _toolaBar.add(_explorer);
    }


    private void actionListeners() {
        _viewer_button.addActionListener(e ->{
            MapWindow mw = new MapWindow(ViewUtils.getWindow(this), _ctrl);
        });

        _delta_time.addActionListener(e -> {

        });

        _run.addActionListener(e ->{
            _stopped = false;
            setEnability(_stopped);
            _stop.setEnabled(true);
            run_sim(Integer.parseInt(_steps.getValue().toString()), parseDouble(_delta_time.getText()));
        });

        _regions_button.addActionListener(e ->{
            _changeRegionsDialog.open(ViewUtils.getWindow(this));
        });

        _steps.addChangeListener(e -> {
        });

        _explorer.addActionListener(e -> {
            _fc.showOpenDialog(ViewUtils.getWindow(this));
            File selectedFile =_fc.getSelectedFile();
            if (selectedFile != null) {
                JSONObject jo = null;
                try {
                    jo = new JSONObject(
                            new JSONTokener(new FileInputStream(selectedFile)));
                } catch (FileNotFoundException ex) {
                    ViewUtils.showErrorMsg(ex.getMessage());
                    throw new RuntimeException(ex);
                }

                //System.out.println(jo);
                int width = jo.getInt("width");
                int height = jo.getInt("height");
                int cols = jo.getInt("cols");
                int rows = jo.getInt("rows");
                _ctrl.reset(cols, rows, width, height);
                _ctrl.load_data(jo);
            }
        });
        _stop.addActionListener(e->{
            _stopped= true;
        });
    }

    private JButton createButtonInToolBar( String toolTipText, String iconFileNamePath){
        JButton b = new JButton();
        b.setToolTipText(toolTipText);
        b.setIcon(new ImageIcon(iconFileNamePath));

        _toolaBar.add(Box.createGlue());
        _toolaBar.add(b);
        return  b;
    }

    private void run_sim(int n, double dt) {
        if (n > 0 && !_stopped) {
            try {
                _ctrl.advance(dt);
                SwingUtilities.invokeLater(() -> run_sim(n - 1, dt));
            } catch (Exception e) {
                ViewUtils.showErrorMsg(this, e.getMessage());
                _stopped = true;
                setEnability(_stopped);
            }
        } else {
            _stopped = true;

            setEnability(_stopped);
        }
    }

    private void setEnability(boolean b){
        _explorer.setEnabled(b);
        _viewer_button.setEnabled(b);
        _delta_time.setEnabled(b);
        _steps.setEnabled(b);
        _regions_button.setEnabled(b);
        _run.setEnabled(b);
        _stop.setEnabled(b);
    }

}

