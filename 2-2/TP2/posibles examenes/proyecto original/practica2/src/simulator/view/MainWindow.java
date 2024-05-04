package simulator.view;

import org.json.JSONObject;
import simulator.control.Controller;

import javax.swing.*;
import java.awt.*;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;

public class MainWindow extends JFrame {
    private Controller _ctrl;

    public MainWindow(Controller ctrl) {
        super("[ECOSYSTEM SIMULATOR]");
        _ctrl = ctrl;
        initGUI();
    }

    private void initGUI() {
        JPanel mainPanel = new JPanel(new BorderLayout());
        setContentPane(mainPanel);

        ControlPanel cp = new ControlPanel(_ctrl);
        mainPanel.add(cp,BorderLayout.PAGE_START);

        // crear StatusBar y añadirlo en PAGE_END de mainPanel
        StatusBar sp = new StatusBar(_ctrl);
        mainPanel.add(sp,BorderLayout.PAGE_END);

        // Definición del panel de tablas (usa un BoxLayout vertical)
        JPanel contentPanel = new JPanel();
        contentPanel.setLayout(new BoxLayout(contentPanel, BoxLayout.Y_AXIS));
        mainPanel.add(contentPanel, BorderLayout.CENTER);

        // crear la tabla de especies y añadirla a contentPanel.
        InfoTable speciesTable= new InfoTable("Species", new SpeciesTableModel(_ctrl));
        speciesTable.setPreferredSize(new Dimension(500, 200));
        contentPanel.add(speciesTable);

        // crear la tabla de regiones.
        InfoTable regionsTable = new InfoTable("Regions", new RegionsTableModel(_ctrl));
        regionsTable.setPreferredSize(new Dimension(500, 250));
        contentPanel.add(regionsTable);

        addWindowListener(new WindowListener() {
            @Override
            public void windowOpened(WindowEvent e) {

            }

            @Override
            public void windowClosing(WindowEvent e) {
                ViewUtils.quit(MainWindow.this);
            }

            @Override
            public void windowClosed(WindowEvent e) {

            }

            @Override
            public void windowIconified(WindowEvent e) {

            }

            @Override
            public void windowDeiconified(WindowEvent e) {

            }

            @Override
            public void windowActivated(WindowEvent e) {

            }

            @Override
            public void windowDeactivated(WindowEvent e) {

            }
        });
        setDefaultCloseOperation(DO_NOTHING_ON_CLOSE);
        pack();
        setVisible(true);
    }


}