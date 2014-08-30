import comp102x.IO;
/**
 * Write a description of class wk2_task2 here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class wk2_task2
{
    
    public static void main()
    {
        IO.output("Enter a: ");
        double a=IO.inputDouble();
        IO.output("Enter b: ");
        double b=IO.inputDouble();
        IO.output("Enter c: ");
        double c=IO.inputDouble();
        double d=(b*b)-(4*a*c);
        double sqrd=Math.sqrt(d);
        double x1=(-b+sqrd)/(2.0*a);
        double x2=(-b-sqrd)/(2.0*a);
        IO.outputln("First solution for x = "+x1);
        IO.outputln("Second solution for x = "+x2);
    }
}
