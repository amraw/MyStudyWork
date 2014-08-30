import comp102x.*;
/**
 * Write a description of class ColorImageDemo here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class ColorImageDemo
{
    private Canvas canvas=new Canvas();
    private ColorImage image1=new ColorImage();
    
    public ColorImageDemo(){
        canvas.add(image1,0,0);
    }
    public ColorImageDemo(int x,int y){
        image1=new ColorImage();
        canvas.add(image1,x,y);
    }
    public void setRotateDemo(int degrees){
        image1.setRotation(degrees);
    }
    public int getRotateDemo(){
        return image1.getRotation();
    }
    public void scaleDemo(double scaleFactor){
        image1.setScale(scaleFactor);
    }
    public void translateDemo(int x,int y){
        image1.setX(x);
        image1.setY(y);
    }
}
