package proyectoIS.view;

import javax.swing.*;
import java.awt.*;

public class PanelAltaVehiculo extends JPanel{

    JTextPane _matricula_vehiculo_text_field;
    JTextPane _tipo_vehiculo_text_field;
    JTextPane _modelo_vehiculo_text_field;
    JButton guardar;

    public PanelAltaVehiculo() {
        initGUI();
    }

    private void initGUI() {
        setBackground(Color.decode("#D0CCD0"));
        setLayout(new BoxLayout(this, BoxLayout.X_AXIS));  //box layout

        JPanel contentPane = new JPanel();
        contentPane.add(new JLabel("Nuevo vehiculo"), BorderLayout.NORTH);
        creaCampo(contentPane, new JLabel("Matricula: "), _matricula_vehiculo_text_field);
        creaCampo(contentPane, new JLabel("Tipo: "), _tipo_vehiculo_text_field);
        creaCampo(contentPane, new JLabel("Modelo: "), _modelo_vehiculo_text_field);

        JButton guardar = new JButton("Guardar");
        contentPane.add(guardar);

        add(contentPane);
        setPreferredSize(new Dimension(MainWindow.width, MainWindow.height));
        setVisible(true);
    }

    private void creaCampo(JPanel contentPane, JLabel label, JTextPane area_texto) {
        area_texto = new JTextPane();
        area_texto.setPreferredSize(new Dimension(100, 30));
        contentPane.add(label);
        contentPane.add(area_texto);

    }


}
