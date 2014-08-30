import comp102x.IO;
/**
 * A class of Car objects that can move forward,backward and turn
 */
public class Car{
    // Below are instance variable
    private int odometer=0;
    private String owner="NoName";
    
    public Car(){} // Default Constructor
    
    public Car(String name){
        owner=name;
    }
    // Three parameter
    public void moveCar(int dist){
        odometer=odometer+Math.abs(dist);
        IO.outputln(owner+" 's car has moved"+dist+" units.");
    }
    public void turnCar(double angle)
    {
        IO.outputln(owner+" 's car has turned"+angle+ " degrees.");
    }
    public int getOdometer(){
        return odometer;
    }
}
    