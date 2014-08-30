import javax.swing.*;


public class MyFrame {
public MyFrame(){}
public void creatFrame(){
	JFrame frame=new JFrame();
	frame.setTitle("My Frame");
	frame.setSize(400,400);
	frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	
	frame.setVisible(true);
}

public static void main(String []args){
	MyFrame frame=new MyFrame();
	frame.creatFrame();
}
}
