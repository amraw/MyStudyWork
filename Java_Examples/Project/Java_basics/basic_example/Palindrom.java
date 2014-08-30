import java.util.*;
/**
 * Write a description of class Palindrom here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Palindrom
{
    
    public static Scanner in;
    public static void main(String []args)
    {
        String original,reverse="";
        System.out.println("Enter the string");
        in=new Scanner(System.in);
        original=in.nextLine();
        int length=original.length();
        for(int i=length-1;i>=0;i--)
        reverse+=original.charAt(i);
        if(original.equals(reverse))
        System.out.println("The string is palindrom");
        else
        System.out.println("The string is not palindrom");
    }
    
}
