import comp102x.IO;
/**
 * Write a description of class wk2_task3 here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class wk2_task3
{
    public static void main()
    {
        IO.output("Enter the width of the triangle: ");
        double x=IO.inputDouble();
        IO.output("Enter the height of the triangle: ");
        double y=IO.inputDouble();
        double ans=(x*y)/2;
        IO.outputln("Answer = "+ans);
    }
}
