import javax.swing.*;
import java.awt.*;

public class MiVentana extends JFrame {
    public MiVentana(){
        super("mi ventana");
        initGUI();
    }

    public void initGUI(){
        JPanel  panel = new JPanel();
        panel.setBackground(Color.RED);
        panel.setBounds(10,10, 50,50);

    }
}
