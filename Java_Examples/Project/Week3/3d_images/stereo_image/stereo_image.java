import comp102x.*;
/**
 * Write a description of class stereo_image here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class stereo_image
{
    private ColorImage leftImage=new ColorImage();
    private ColorImage rightImage=new ColorImage();
    Canvas canvas;
    public stereo_image()
    {
        int width=leftImage.getWidth();
        int height=rightImage.getHeight();
        canvas=new Canvas(width,height);
    }
    void creatStereoImage()
    {
        ColorImage redImage=leftImage.createRedImage();
        ColorImage cyanImage=rightImage.createCyanImage();
        ColorImage stereoImage=redImage.add(cyanImage);
        canvas.add(stereoImage,0,0);
    }
}
