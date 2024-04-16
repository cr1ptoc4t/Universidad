
import javax.swing.*;
        import java.awt.*;
        import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.util.Objects;
import java.util.regex.Pattern;

public class MainWindow extends JFrame implements KeyListener, Observer {

    private JTextField textoCalculadora;
    private String opAnt;
    private String opSig;
    private String num1, num2;
    private Controller _ctrl;

    MainWindow(Controller ctrl){
        super("calculadora");
        opAnt="";
        opSig="";
        this._ctrl = ctrl;
        initGUI();
        _ctrl.addObserver(this);
    }



    public JButton crearBotonNumerico(String text){
        JButton b = new JButton(text);
        b.addActionListener((ActionEvent e)->{
            textoCalculadora.setText(textoCalculadora.getText()+b.getActionCommand());
        } );
        b.getActionCommand();
        return b;
    }



    public JButton crearBotonOperacion(String text){
        JButton b = new JButton(text);
        b.addActionListener(e -> {
            if(opAnt==""){
                num1=textoCalculadora.getText();
                opAnt = b.getActionCommand();
                textoCalculadora.setText(textoCalculadora.getText()+ opAnt);
            } else{
                String todo = textoCalculadora.getText();
                String num2 = todo.split(Pattern.quote(opAnt))[1];
                double resultado=_ctrl.executeOperation(num1, num2, opAnt);

                if(Objects.equals(e.getActionCommand(), "="))
                {
                    textoCalculadora.setText(""+ resultado+ e.getActionCommand());
                    opAnt="";

                } else {
                    textoCalculadora.setText(""+ resultado);
                    opAnt=e.getActionCommand();

                }

            }
        });
        return b;
    }



    public void initGUI(){

        JPanel panelPrincipal = new JPanel(new BorderLayout());
        JPanel panelSuperior = new JPanel();
        panelSuperior.setLayout(new BoxLayout(panelSuperior, BoxLayout.LINE_AXIS));

        textoCalculadora = new JTextField(30);

        JButton botonC = new JButton("C");

        botonC.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                textoCalculadora.setText("");
                num1="";
                opAnt="";
                System.out.println("borra");
                _ctrl.clear();
            }
        });


        panelSuperior.add(textoCalculadora);
        panelSuperior.add(botonC);
        panelPrincipal.add(panelSuperior, BorderLayout.PAGE_START);

        JPanel panelInferior= new JPanel(new GridLayout(3,5));
        panelInferior.setLayout(new BoxLayout(panelInferior,2));

        JPanel panelNumerico = new JPanel(new GridLayout(3, 3));
        JPanel panelOperaciones = new JPanel(new GridLayout(3, 2));

        panelInferior.add(panelNumerico);
        panelInferior.add(panelOperaciones);

        for(int i=3; i>0; i--)
            for(int j=3; j>0; j--)
                panelNumerico.add(crearBotonNumerico(""+(i*3-(j+1)+2)));

        panelOperaciones.add(crearBotonNumerico("*"));
        panelOperaciones.add(crearBotonNumerico("/"));
        panelOperaciones.add(crearBotonNumerico("="));
        panelOperaciones.add(crearBotonNumerico("+"));
        panelOperaciones.add(crearBotonNumerico("+"));
        panelOperaciones.add(crearBotonNumerico("+"));


        panelPrincipal.add(panelSuperior, BorderLayout.PAGE_START);
        panelPrincipal.add(panelInferior, BorderLayout.PAGE_END);


        this.setContentPane(panelPrincipal);
        //siempre hacer esto, si no no se ve
        this.setVisible(true);
        this.setLocation(200,200);
        this.pack();
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        //

    }

    // pulsar normal
    @Override
    public void keyTyped(KeyEvent e) {
        if (e.getKeyChar()=='c'|| e.getKeyChar()== 'C'){
            JButton c = new JButton();
            c.getActionListeners()[0].actionPerformed(new ActionEvent(c, 0, "C"));
        }
    }

    //pulsar (p1)
    @Override
    public void keyPressed(KeyEvent e) {

    }

    //levantar (p2)
    @Override
    public void keyReleased(KeyEvent e) {

    }
}
