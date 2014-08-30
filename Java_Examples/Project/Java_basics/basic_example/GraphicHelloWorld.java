
import javax.swing.*;
/**
 * Write a description of class BoxLayout here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class GraphicHelloWorld
{
    public static void creatAndShowGUI()
    {
        JFrame frame=new JFrame("HelloWrold");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setBounds(100,100,200,100);
        JLabel label=new JLabel("Hello World");
        frame.getContentPane().add(label);
        frame.setVisible(true);
        
    }
    public static void main(String []args)
    {
        javax.swing.SwingUtilities.invokeLater(new Runnable(){
           public void run(){
               creatAndShowGUI();
            }
        });
    }
}
