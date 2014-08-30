import comp102x.*;
/**
 * Write a description of class image_experiment here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class image_experiment
{
   ColorImage image=new ColorImage();
   Canvas canvas;
   public image_experiment()
   {
       int width=image.getWidth();
       int height=image.getHeight();
       canvas=new Canvas(width,height);
    }
    public void imageexp()
    {
        ColorImage red_image=image.createRedImage();
        ColorImage cyan_image=image.createCyanImage();
        ColorImage realImage=red_image.multiply(cyan_image);
        canvas.add(realImage);
    }
}
