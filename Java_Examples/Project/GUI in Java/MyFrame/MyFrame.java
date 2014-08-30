import java.awt.*;
import javax.swing.*;
import javafx.scene.layout.*;
public class MyFrame extends JFrame
{
    JPanel pane=new JPanel();
    public MyFrame()
    {
        setTitle("My Frame");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocation(200,400);
        setSize(400,200);
        setVisible(true);
        
        JPanel content = new JPanel();
        content.setLayout(new FlowLayout());
        
        JLabel label=new JLabel("Panel Label");
        content.add(label);
        
        JButton button=new JButton("Click Me");
        content.add(button);
        
        setContentPane(content);
    }
}
