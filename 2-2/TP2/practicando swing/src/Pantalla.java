import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.util.Objects;
import java.util.regex.Pattern;


public class Pantalla extends JFrame implements KeyListener {

    Pantalla(){
        super("");
        initGUI();
    }


    public void initGUI(){
        JTextArea saludo = new JTextArea("Hola amorch");
        JPanel panelPrincipal = new JPanel(new GridLayout());

        JButton botonC = new JButton("Sí");
        panelPrincipal.add(saludo);
        panelPrincipal.add(botonC);

        botonC.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                //reubicar boton
            }
        });

        this.setContentPane(panelPrincipal);
        //siempre hacer esto, si no no se ve
        this.setVisible(true);
        this.setLocation(200,200);
        this.pack();
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        //
    }
    @Override
    public void keyTyped(KeyEvent e) {

    }

    @Override
    public void keyPressed(KeyEvent e) {

    }

    @Override
    public void keyReleased(KeyEvent e) {

    }
}
