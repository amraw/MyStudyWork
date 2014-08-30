
public class PowerCalculator
{
    /**
     * Calculate the non-negative power of an integer number. If a negative power is input, the method returns 1.
     * 
     * @param number The number to take power.
     * @param power The power factor to be taken to.
     * @return The calculation result after taking power of the integer number.
     */
    public static long powerN(int number, int power) {
        
        // write your code after this line
        long result=1;
        if(power<0)
         return 1;
        else
        for(int i=1;i<=power;i++)
        result*=number;
        
        
        return result; // remove this line after completing your code
    }
}
