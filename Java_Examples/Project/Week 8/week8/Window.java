import comp102x.*;
import java.awt.event.*;
import javax.swing.*;
import java.awt.*;
/**
 * Write a description of class MyListener here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Window extends JFrame implements MouseListener
{
    public void myWindow(){
        setTitle("Hello World");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(400,200);
        setVisible(true);
        
        JPanel content=new JPanel();
        content.setLayout(new FlowLayout());
        
        JLabel label=new JLabel("Panel Label");
        content.add(label);
        
        JButton button=new JButton("Click Me");
        content.add(button);
        button.addMouseListener(this);
        setContentPane(content);
    }
    
    public void mouseClicked(MouseEvent e){
        
    }
    public void mousePressed(MouseEvent e)
    {}
    public void mouseReleased(MouseEvent e)
    {}
    public void mouseEntered(MouseEvent e)
    {}
    public void mouseExited(MouseEvent e)
    {}
}
