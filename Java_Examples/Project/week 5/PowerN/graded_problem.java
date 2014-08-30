
/**
 * Write a description of class graded_problem here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class graded_problem
{
   
    public static int fact2(int n1, int n2) {  

    int t = 1; // initialize t to 1       
    for (int counter = n1; counter <= n2; counter++) {
        t = t * counter;
    }
    return t;
}
}
