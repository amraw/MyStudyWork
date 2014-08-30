import java.util.*;
/**
 * Write a description of class Factorial here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Factorial
{
    private static Scanner sc;
    public static void main(String []args)
    {
        int n,c,fact=1;
        System.out.print("Enter the number: ");
        sc=new Scanner(System.in);
        n=sc.nextInt();
        for(c=1;c<=n;c++)
         fact=fact*c;
        System.out.println("The factorial is "+fact);
    }
}
