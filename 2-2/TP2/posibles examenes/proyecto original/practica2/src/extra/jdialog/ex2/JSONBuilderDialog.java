package extra.jdialog.ex2;

import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;
import javax.swing.table.TableCellRenderer;
import javax.swing.table.TableColumn;

import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.DefaultComboBoxModel;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JDialog;
import javax.swing.JLabel;
import java.awt.*;

class JSONBuilderDialog extends JDialog {

	private static final long serialVersionUID = 1L;

	private int _status;
	private DefaultTableModel _dataTableModel;
	private String[] _header = { "Key", "Value" };
	private String[][] _jsonSrc = { //
			{ "name", "age", "weight" }, //
			{ "city", "country" }, //
			{ "team", "points", "game", "value" } //
	};

	JSONBuilderDialog() {
		super((Frame) null, true);
		initGUI();
	}

	@SuppressWarnings("serial")
	private void initGUI() {

		_status = 0;

		setTitle("Build JSON from Table");
		JPanel mainPanel = new JPanel();
		mainPanel.setLayout(new BoxLayout(mainPanel, BoxLayout.Y_AXIS));
		setContentPane(mainPanel);

		// help
		JLabel help = new JLabel("<html><p>Fill in the table and click OK</p></html>");

		help.setAlignmentX(CENTER_ALIGNMENT);
		mainPanel.add(help);

		mainPanel.add(Box.createRigidArea(new Dimension(0, 20)));

		// data table
		_dataTableModel = new DefaultTableModel() {
			@Override
			public boolean isCellEditable(int row, int column) {
				return column != 0;
			}
		};
		_dataTableModel.setColumnIdentifiers(_header);
		updateTableModel(0);
		JTable dataTable = new JTable(_dataTableModel) {
			private static final long serialVersionUID = 1L;

			// we override prepareRenderer to resize columns to fit to content
			@Override
			public Component prepareRenderer(TableCellRenderer renderer, int row, int column) {
				Component component = super.prepareRenderer(renderer, row, column);
				int rendererWidth = component.getPreferredSize().width;
				TableColumn tableColumn = getColumnModel().getColumn(column);
				tableColumn.setPreferredWidth(
						Math.max(rendererWidth + getIntercellSpacing().width, tableColumn.getPreferredWidth()));
				return component;
			}
		};
		JScrollPane tabelScroll = new JScrollPane(dataTable, JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED,
				JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);
		mainPanel.add(tabelScroll);

		mainPanel.add(Box.createRigidArea(new Dimension(0, 20)));

		// ctrl panel
		JPanel ctrlPanel = new JPanel();
		ctrlPanel.setAlignmentX(CENTER_ALIGNMENT);
		mainPanel.add(ctrlPanel);

		// combox box for selecting the data src
		DefaultComboBoxModel<String> dataSelectorModel = new DefaultComboBoxModel<>();
		for (int i = 0; i < _jsonSrc.length; i++)
			dataSelectorModel.addElement("DATA-" + i);
		JComboBox<String> dataSelector = new JComboBox<String>(dataSelectorModel);
		dataSelector.addActionListener((e) -> {
			updateTableModel(dataSelector.getSelectedIndex());
		});
		ctrlPanel.add(dataSelector);

		// cancel
		JButton cancelButton = new JButton("Cancel");
		cancelButton.addActionListener((e) -> {
			_status = 0;
			setVisible(false);
		});
		ctrlPanel.add(cancelButton);

		// OK
		JButton okButton = new JButton("OK");
		okButton.addActionListener((e) -> {
			_status = 1;
			JSONBuilderDialog.this.setVisible(false);
		});
		ctrlPanel.add(okButton);

		setPreferredSize(new Dimension(400, 400));

		pack();
		setResizable(false); // change to 'true' if you want to allow resizing
		setVisible(false); // we will show it only when open is called
	}

	private void updateTableModel(int _dataIdx) {
		String[] keys = _jsonSrc[_dataIdx];
		_dataTableModel.setNumRows(keys.length);
		for (int i = 0; i < keys.length; i++) {
			_dataTableModel.setValueAt(keys[i], i, 0);
			_dataTableModel.setValueAt("", i, 1);
		}
	}

	public String getJSON() {
		StringBuilder s = new StringBuilder();
		s.append('{');
		for (int i = 0; i < _dataTableModel.getRowCount(); i++) {
			String k = _dataTableModel.getValueAt(i, 0).toString();
			String v = _dataTableModel.getValueAt(i, 1).toString();
			if (!v.isEmpty()) {
				s.append('"');
				s.append(k);
				s.append('"');
				s.append(':');
				s.append(v);
				s.append(',');
			}
		}

		if (s.length() > 1)
			s.deleteCharAt(s.length() - 1);
		s.append('}');

		return s.toString();
	}

	public int open(Frame parent) {

		if (getParent() != null)
			setLocation(//
					parent.getLocation().x + parent.getWidth() / 2 - getWidth() / 2, //
					parent.getLocation().y + parent.getHeight() / 2 - getHeight() / 2);
		pack();
		setVisible(true);
		return _status;
	}

}
