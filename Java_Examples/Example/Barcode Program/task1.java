import comp102x.IO;
/**
 * Write a description of class task1 here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class task1
{
    public static void main()
    {
        IO.output("Enter an integer, x: ");
        int x=IO.inputInteger();
        IO.output("Enter an integer, : ");
        int y=IO.inputInteger();
        int ans=x*y;
        IO.outputln("Answer = "+ans);
    }
}