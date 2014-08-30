import java.util.*;
public class InputString
{
   private static Scanner in;
   public static void main(String []args)
   {
      System.out.println("Enter the name: ");
      in=new Scanner(System.in);
       String name;
       name=in.nextLine();
       int length=name.length();
       System.out.println("The name is "+name);
       System.out.println("The length of name is "+length);
       
   }
}
