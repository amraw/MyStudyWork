import java.util.Scanner;
/**
 * Write a description of class AlphabaticSort here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class AlphabaticSort
{
    static Scanner in;
    public static void main(String []args)
    {
        int i,j,n;
        in=new Scanner(System.in);
        System.out.print("Enter the value of n\n");
        n=in.nextInt();
        String[] name=new String[8];
        String[] tname=new String[8];
        String temp;
        System.out.printf("Enter "+n+" names ");
        for(i=0;i<n-1;i++)
        {
            name[i]=in.nextLine();
            tname[i]=name[i];
        }
        for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
        {
            if(name[i].compareToIgnoreCase(name[j])>0)
            {
                temp=name[i];
                name[i]=name[j];
                name[j]=temp;
            }
        }
    }
}
