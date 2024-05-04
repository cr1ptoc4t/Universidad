package simulator.view;

import org.json.JSONArray;
import org.json.JSONObject;
import simulator.control.Controller;
import simulator.model.EcoSysObserver;
import simulator.model.animals.AnimalInfo;
import simulator.model.regionmanager.MapInfo;
import simulator.model.regionmanager.RegionInfo;
import simulator.launcher.Main;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import javax.swing.table.JTableHeader;
import java.awt.*;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Vector;

class ChangeRegionsDialog extends JDialog implements EcoSysObserver {
    private DefaultComboBoxModel<String> _regionsModel;
    private DefaultComboBoxModel<String> _fromRowModel;
    private DefaultComboBoxModel<String> _toRowModel;
    private DefaultComboBoxModel<String> _fromColModel;
    private DefaultComboBoxModel<String> _toColModel;
    private DefaultTableModel _dataTableModel;

    private Controller _ctrl;
    private List<JSONObject> _regionsInfo;
    private Frame _parent;
    private int _status = 0;

    private JComboBox _row_from_combobox;
    private JComboBox _row_to_combobox;
    private JComboBox _col_from_combobox;
    private JComboBox _col_to_combobox;
    private JComboBox regionTypeBox;
    private JTable table;

    private int _cols;
    private int _rows;


    private static final String dialogText = "<html><p>Select a region type, the rows/cols interval, and provide values " +
            "for the parameters in the Value column (default values<br>are used for parameters with no value)</p></html>";

    private final String[] _headers = {"Key", "Value", "Description"};

    ChangeRegionsDialog(Controller ctrl, Frame parent) {
        super((Frame) null, true);
        this._parent = parent;
        this._ctrl = ctrl;
        this._regionsInfo = new ArrayList<JSONObject>();
        initGUI();

        this._ctrl.addObserver(this);
    }

    private void initGUI() {
        setTitle("Change Regions");
        JPanel mainPanel = new JPanel();
        mainPanel.setLayout(new BoxLayout(mainPanel, BoxLayout.Y_AXIS));
        setContentPane(mainPanel);

        //crear paneles organizacion
        JPanel helpTextPanel = new JPanel();
        mainPanel.add(helpTextPanel);

        JPanel tablePanel = new JPanel(new BorderLayout());
        mainPanel.add(tablePanel, BorderLayout.CENTER);

        JPanel comboBoxPanel = new JPanel();
        mainPanel.add(comboBoxPanel);

        JPanel buttonsPanel = new JPanel();
        mainPanel.add(buttonsPanel);

        // crear el texto de ayuda
        createHelpText(helpTextPanel);

        // _regionsInfo se usará para establecer la información en la tabla
        _regionsInfo = Main.regionFactory.get_info();

        // _dataTableModel es un modelo de tabla que incluye todos los parámetros de la region
        _dataTableModel = new DefaultTableModel() {
            @Override
            public boolean isCellEditable(int row, int column) {
                return column == 1;
            }

            public String getColumnName(int col) {
                return _headers[col];
            }
        };


        fillTablePanel(tablePanel);

        // _regionsModel es un modelo de combobox que incluye los tipos de regiones
        _regionsModel = new DefaultComboBoxModel<>();
        _toColModel = new DefaultComboBoxModel<>();
        _toRowModel = new DefaultComboBoxModel<>();
        _fromColModel = new DefaultComboBoxModel<>();
        _fromRowModel = new DefaultComboBoxModel<>();

        fillComboboxValues();
        fillComboboxPanel(comboBoxPanel);

        // añade la descripción de todas las regiones a _regionsModel
        for (JSONObject region : _regionsInfo) {
            _regionsModel.addElement(region.getString("type"));
        }

        fillButtonsPanel(buttonsPanel);
        fillTable();

        setPreferredSize(new Dimension(700, 400)); // puedes usar otro tamaño
        pack();
        setResizable(false);
        setVisible(false);
    }

    private void fillTablePanel(JPanel tablePanel) {
        _dataTableModel.setColumnIdentifiers(_headers);
        table = new JTable(_dataTableModel);
        tablePanel.add(new JScrollPane(table), BorderLayout.CENTER);

    }

    private void createHelpText(JPanel helpTextPanel) {
        JLabel helpLabel = new JLabel(dialogText);
        helpLabel.setAlignmentX(CENTER_ALIGNMENT);
        helpTextPanel.add(helpLabel);
    }


    private void fillComboboxValues() {
        for (int i = 0; i < _rows; i++) {
            _fromRowModel.addElement(i + "");
            _toRowModel.addElement(i + "");
        }

        for (int i = 0; i < _cols; i++) {
            _fromColModel.addElement(i + "");
            _toColModel.addElement(i + "");
        }

    }

    private String parseDefaultValue(String desc) {
        int index = desc.indexOf("default");
        if (index != -1) {
            String substring = desc.substring(index + "default".length(), desc.indexOf(')')).trim();
            String[] parts = substring.split("\\s+");
            if (parts.length > 0) return parts[0];
        }
        return "0";
    }

    private void fillButtonsPanel(JPanel panel) {
        JButton ok = new JButton("OK");
        ok.addActionListener(a -> {

            JSONObject region_spec = create_region_spec();

            int row_from = Integer.parseInt(_row_from_combobox.getSelectedItem().toString());
            int row_to = Integer.parseInt(_row_to_combobox.getSelectedItem().toString());
            int col_from = Integer.parseInt(_col_from_combobox.getSelectedItem().toString());
            int col_to = Integer.parseInt(_col_to_combobox.getSelectedItem().toString());

            if (col_from > col_to || row_from > row_to) {
                ViewUtils.showErrorMsg(this, "Valores erróneos");
            } else {
                JSONObject regions = create_regions_JSONObject(row_from, row_to, col_from, col_to, region_spec);
                _ctrl.set_regions(regions);
                _status = 1;
                this.setVisible(false);
            }
        });

        JButton cancel = new JButton("Cancel");
        cancel.addActionListener(a -> {
            _status = 0;
            this.setVisible(false);
        });

        panel.add(cancel);
        panel.add(ok);
    }



    private JSONObject create_region_spec() {

        JSONObject spec = null;

        for(JSONObject jo: _regionsInfo){
            String selectedItem = _regionsModel.getSelectedItem().toString();
            String type = jo.getString("type");
            if(selectedItem.equals(type)){
                spec = new JSONObject(jo, new String[]{"data", "type"});
                JSONObject data_to_modify = spec.getJSONObject("data");
                for(int i=0; i<_dataTableModel.getRowCount();i++) {
                    String desc = _dataTableModel.getValueAt(i, 0).toString();
                    String value = _dataTableModel.getValueAt(i, 1).toString();
                    if(value.isEmpty())
                        data_to_modify.remove(desc);
                    else
                        data_to_modify.put(desc, Double.parseDouble(value));
                }
                spec.put("data", data_to_modify);

            }
        }

        return spec;
    }

    private JSONObject create_regions_JSONObject(int row_from, int row_to, int col_from, int col_to, JSONObject region_data) {
        JSONObject ret = new JSONObject();
        JSONArray regions = new JSONArray();

        JSONObject region1 = new JSONObject();
        JSONArray row = new JSONArray();
        row.put(row_from);
        row.put(row_to);

        JSONArray col = new JSONArray();
        col.put(col_from);
        col.put(col_to);

        region1.put("row", row);
        region1.put("col", col);
        region1.put("spec", region_data);

        regions.put(region1);
        ret.put("regions", regions);

        return ret;
    }


    public void open(Frame parent) {
        setLocation(
                parent.getLocation().x + parent.getWidth() / 2 - getWidth() / 2,
                parent.getLocation().y + parent.getHeight() / 2 - getHeight() / 2);
        pack();
        setVisible(true);
    }


    private void fillComboboxPanel(JPanel selectsPanel) {

        selectsPanel.add(new JLabel("Region type: "));
        regionTypeBox = new JComboBox(_regionsModel);
        regionTypeBox.addActionListener(e ->{
            clearTable();
            fillTable();
        });

        selectsPanel.add(regionTypeBox);

        selectsPanel.add(new JLabel("Row from/to: "));

        _row_from_combobox = new JComboBox(_fromRowModel);
        _row_to_combobox = new JComboBox(_toRowModel);

        selectsPanel.add(_row_from_combobox);
        selectsPanel.add(_row_to_combobox);

        selectsPanel.add(new JLabel("Column from/to: "));

        _col_from_combobox = new JComboBox(_fromColModel);
        _col_to_combobox = new JComboBox(_toColModel);

        selectsPanel.add(_col_from_combobox);
        selectsPanel.add(_col_to_combobox);
    }

    private void fillTable() {
        JSONObject info = _regionsInfo.get(regionTypeBox.getSelectedIndex());
        JSONObject data = info.getJSONObject("data");

        for(String key:data.keySet()){
            String desc = data.get(key).toString();
            String defaultValue = parseDefaultValue(desc);
            String [] fila = {key, defaultValue, desc};
            _dataTableModel.addRow(fila);
        }
    }

    private void clearTable() {
        int size = _dataTableModel.getRowCount();
        for(int i=0; i<size; i++)
            _dataTableModel.removeRow(0);
    }

    private void clearComboboxValues() {
        _fromColModel.removeAllElements();
        _fromRowModel.removeAllElements();
        _toRowModel.removeAllElements();
        _toColModel.removeAllElements();
    }

    @Override
    public void onRegister(double time, MapInfo map, List<AnimalInfo> animals) {
        _cols = map.get_cols();
        _rows = map.get_rows();
        fillComboboxValues();
    }

    @Override
    public void onReset(double time, MapInfo map, List<AnimalInfo> animals) {
        clearComboboxValues();
        _cols = map.get_cols();
        _rows = map.get_rows();
        fillComboboxValues();
    }

    @Override
    public void onAnimalAdded(double time, MapInfo map, List<AnimalInfo> animals, AnimalInfo a) {

    }

    @Override
    public void onRegionSet(int row, int col, MapInfo map, RegionInfo r) {

    }

    @Override
    public void onAvanced(double time, MapInfo map, List<AnimalInfo> animals, double dt) {

    }
}