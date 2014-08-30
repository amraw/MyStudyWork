import comp102x.*;
/**
 * Write a description of class optional_task1 here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class optional_task1
{
    public void changeColor()
    {
        ColorImage image = new ColorImage();
        image.increaseRed(40);
        Canvas canvas = new Canvas(image.getWidth(), image.getHeight());
        canvas.add(image);
        
        //image.save();
    }
}
