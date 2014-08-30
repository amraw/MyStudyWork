import comp102x.*;
/**
 * Write a description of class task2 here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class task2
{
    public void loadAnImage(){
   ColorImage colImage1=new ColorImage("A.jpg");
   ColorImage colImage2=new ColorImage("B.jpg");
   ColorImage colImage3=colImage1.add(colImage2);
   int width1=colImage1.getWidth();
   int height1=colImage1.getHeight();
   int width2=colImage2.getWidth();
   int width3=colImage3.getWidth();
   Canvas canvas=new Canvas((width1+width2+width3),height1);
   canvas.add(colImage1,0,0);
   canvas.add(colImage2,width1+10,0);
   canvas.add(colImage3,width2+10,0);
}
}
