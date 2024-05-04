package simulator.view;

import javax.swing.*;
import javax.swing.border.Border;
import javax.swing.border.TitledBorder;
import javax.swing.table.JTableHeader;
import javax.swing.table.TableModel;
import java.awt.*;

public class InfoTable extends JPanel {
    String _title;
    TableModel _tableModel;
    InfoTable(String title, TableModel tableModel) {
        if(title==null|| tableModel==null)
            throw new IllegalArgumentException();
        _title = title;
        _tableModel = tableModel;
        initGUI();
    }
    private void initGUI() {
        setLayout(new BorderLayout());

        Border border = BorderFactory.createLineBorder(Color.BLACK);
        Border titledBorder = BorderFactory.createTitledBorder(border, _title);

        setBorder(titledBorder);

        JTable table = new JTable(_tableModel);
        JScrollBar scrollBar = new JScrollBar(Scrollbar.VERTICAL);
        table.add(scrollBar);

        add(new JScrollPane(table));
    }
}


