import javax.swing.*;
import java.awt.*;

public class MiVentana extends JFrame {
    public MiVentana(){
        super("mi ventana");
        initGUI();
    }

    public JButton createButton(String text){
        JButton b =new JButton(text);
        b.setPreferredSize(new Dimension(100, 100));
        b.setMaximumSize(new Dimension(50,50));
        return b;
    }

    public void initGUI(){
        JPanel  panel = new JPanel();
        panel.setVisible(true);
        panel.setLayout(new GridLayout(3,3));

        for(int i=0; i<9;i++){
            panel.add(createButton(""+ i));
        }

        this.setContentPane(panel);

        panel.setBackground(Color.RED);
        panel.setBounds(10,10, 50,50);

    }
}
