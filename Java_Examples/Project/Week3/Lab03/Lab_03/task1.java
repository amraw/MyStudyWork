import comp102x.*;
/**
 * Write a description of class task1 here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class task1
{
   public void loadAnImage(){
   ColorImage colImage=new ColorImage("A.jpg");
   int width=colImage.getWidth();
   int height=colImage.getHeight();
   Canvas canvas=new Canvas(width,height);
   canvas.add(colImage,0,0);
}
}
