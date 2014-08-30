import comp102x.*;
/**
 * This class is for understanding the use of class
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class car_basic
{
    // instance variables - replace the example below with your own
    public Canvas canvas= new Canvas();
    public ColorImage image1=new ColorImage();
    
    public void setAndOutput(){
        canvas.add(image1,0,0);
        image1.setX(50);
        image1.setY(100);
        image1.setRotation(45);
    }

    
}
