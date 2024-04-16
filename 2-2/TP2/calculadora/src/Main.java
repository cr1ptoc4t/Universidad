import javax.swing.*;

public class Main {
    public static void main(String[] args) {
        Controller ctrl = new Controller();
        SwingUtilities.invokeLater(()-> new MainWindow(ctrl));
    }
}

/*
* en el campus esta el de nuestra calculadora
* coger el codigo y refactorizarlo usando mvc
* con observers
* que funcione igual pero mejor estructurada
* 5 clases?
*
* PASO 2
* crear otra vista que sea :
*   _______________________________
*   |                             |
*   |  -------------------------  |
*   |  | textfield | textfield |  |
*   |  -------------------------  |
*   |  |  +  |  -  |  *  |  /  |  |
*   |  -------------------------  |
*   |  | Resultado             !  |
*   |  -------------------------  |
*   |_____________________________|
* dos ventanas
* que funcione por consola
* si tocamos la consola, sale en todas las ventanas
* voluntario: que el resultado solo se muestre en
  la pantalla que se ven los datos (con un booleano)
 */