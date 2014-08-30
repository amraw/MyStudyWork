import comp102x.IO;
/**
 * Write a description of class exercise_test here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class ExerciseTest
{
    int x;
    public ExerciseTest(int x)
    {
        x=x;
    }
    public static void main(){
        ExerciseTest t=new ExerciseTest(10);
        System.out.println(t.x);
    }
}
