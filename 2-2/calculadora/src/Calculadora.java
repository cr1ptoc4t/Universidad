import javax.swing.*;
import java.awt.*;

public class Calculadora extends JFrame {

    private JTextField textoCalculadora;
    Calculadora(){
        super("calculadora");
        initGUI();
    }

    public JButton crearBotonNumerico(String text){
        JButton b = new JButton(text);
        b.getActionCommand();
        return b;
    }
    public JButton crearBotonOperacion(String text){
        JButton b = new JButton(text);
        b.getActionCommand();
        return b;
    }

    public void initGUI(){

        JPanel panelPrincipal = new JPanel(new BorderLayout());
        JPanel panelSuperior = new JPanel();
        panelSuperior.setLayout(new BoxLayout(panelSuperior, BoxLayout.LINE_AXIS));

        textoCalculadora = new JTextField(30);

        JButton botonC = new JButton("C");

        panelSuperior.add(textoCalculadora);
        panelSuperior.add(botonC);
        panelPrincipal.add(panelSuperior, BorderLayout.PAGE_START);

        JPanel panelInferior= new JPanel(new GridLayout(3,5));

        for(int i=0; i<15; i++) {
            panelInferior.add(crearBotonNumerico(""+i));
        }

        panelPrincipal.add(panelSuperior, BorderLayout.PAGE_START);



        this.setContentPane(panelPrincipal);
        //siempre hacer esto, si no no se ve
        this.setVisible(true);
        this.setLocation(200,200);
        this.pack();
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        //

    }
}
