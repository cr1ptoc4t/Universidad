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
        JTextArea saludo = new JTextArea("Hola amorch,\n vas a renunciar a ser un FIFE por mi?");

        JPanel panelPrincipal = new JPanel(new BorderLayout());
        panelPrincipal.setBackground(new Color(255,100,100));

        saludo.setAlignmentX(getWidth()/2);

        JButton botonC = new JButton("nO");
        JButton botonSi = new JButton("SIIIIII, renunciare al gym, al fútbol, a messi " +
                ".Alabaré a Taylor Swift por encima de mi cadaver "+
                "y en caso de fallecer le donaré mi cuerpo para que pueda dominar el mundo " +
                "y usarme como combustible si tiene que ir a por una " +
                "barra de pan!!!!!!!!!!");
        botonC.setBackground(new Color(255, 100,120));
        botonC.setSize(10, 20);
        botonC.setPreferredSize(new Dimension(40, 40));
        botonC.setMaximumSize(new Dimension(40, 40));
        panelPrincipal.add(saludo, BorderLayout.PAGE_START);
        panelPrincipal.add(botonSi, BorderLayout.CENTER);
        panelPrincipal.add(botonC, BorderLayout.PAGE_END);

        botonC.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                botonC.setLocation((int)(Math.random()*getWidth()), (int)(Math.random()*getHeight()));
            }
        });

        botonSi.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                panelPrincipal.add((new JPanel()).add(new JLabel("OLEEEEEEE")), BorderLayout.CENTER);
            }
        });

        panelPrincipal.setSize(1900, 1900);
        //panelPrincipal.(false);
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
