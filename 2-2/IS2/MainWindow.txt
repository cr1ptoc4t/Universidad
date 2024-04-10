package proyectoIS.view;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionListener;
import java.lang.reflect.InvocationTargetException;

public class MainWindow extends JFrame {
    public static int width=800,height=600;
    private JButton home;

    private JButton _boton_clases;
    private JButton _boton_alumnos;
    private JButton _boton_staff;
    private JButton _boton_vehiculos;


    public MainWindow() {
        super("MAGNO");
        initGUI();
    }

    private void initGUI() {

        JPanel panelPrincipal = new JPanel();
        panelPrincipal.setLayout(new BoxLayout(panelPrincipal, BoxLayout.Y_AXIS));
        panelPrincipal.add(Box.createVerticalGlue());

        toolbar();
        addButtons(panelPrincipal);

        panelPrincipal.add(Box.createVerticalGlue());

        add(panelPrincipal);

        setLocationRelativeTo(null);
        setPreferredSize(new Dimension(width, height));
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        pack();
        setVisible(true);
    }

    private JButton addButton(String buttonText, Dimension d, JPanel container){

        JButton b = new JButton(buttonText);
        b.setPreferredSize(d);
        b.setAlignmentX(Component.CENTER_ALIGNMENT);
        container.add(b);

        JSeparator separator = new JSeparator(1);
        container.add(separator);

        return b;
    }

    private void addButtons(JPanel panelPrincipal) {
        Dimension buttonSize = new Dimension(500, 50);
        _boton_clases= addButton("Clases",buttonSize, panelPrincipal );

        _boton_clases.addActionListener(e-> {

        });

        _boton_alumnos= addButton("Alumnos",buttonSize, panelPrincipal );
        _boton_alumnos.addActionListener(e-> {

        });

        _boton_staff= addButton("Staff",buttonSize, panelPrincipal );
        _boton_staff.addActionListener(e-> {

        });

        _boton_vehiculos= addButton("Vehiculos",buttonSize, panelPrincipal );

        _boton_vehiculos.addActionListener(e-> {
            //invocar panel vehiculos
        });
    }

    private void toolbar() {
        JToolBar toolbar = new JToolBar();
        toolbar.setBackground(Color.decode("#274060"));
        toolbar.setFloatable(false);
        toolbar.setRollover(true);
        toolbar.setPreferredSize(new Dimension(width, 50));
        
        home = createButton("Home", "resources/icons/logo_azul_30x30.png", new Dimension(30,30));
        toolbar.add(home);

        add(toolbar, BorderLayout.PAGE_START);
    }

    private JButton createButton(String toolTipText, String iconFileNamePath, Dimension iconSize){
        JButton b = new JButton();
        b.setToolTipText(toolTipText);
        b.setIcon(new ImageIcon(iconFileNamePath));
        b.setPreferredSize(iconSize);
        return  b;
}
}
