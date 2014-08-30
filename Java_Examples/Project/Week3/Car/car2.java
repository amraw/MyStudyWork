import comp102x.*;
/**
 * Write a description of class week_3_graded_problem_task_3A here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class car2
{
   String owner="NoName";
   ColorImage carImage=new ColorImage("Car1.png");
   double gasMileage=10.0;
   double gasInTank=10.0;
   
   public car2(){}
   public car2(String nameOfOwner,double newGasMileage){
       owner=nameOfOwner;
       carImage=new ColorImage();
       gasMileage=newGasMileage;
    }
    public void moveForward(int dist){
        double rotationInDegrees=carImage.getRotation();
        double rotationInRadians=Math.toRadians(rotationInDegrees);
        double distX=dist * Math.cos(rotationInRadians);
        double distY=dist * Math.sin(rotationInRadians);
        carImage.setX(carImage.getX()+(int)distX);
        carImage.setY(carImage.getY()+(int)distY);
        
        double distKm=dist/100.0;
        double gasUsed=distKm/100.0*gasMileage;
        gasInTank=gasInTank-gasUsed;
        IO.outputln("Amount of gas used:"+gasUsed+",gas remained:"+gasInTank);
    }
    
    public void makeTurn(int angle)
    {
      carImage.setRotation(carImage.getRotation()+angle);
    }
   
    public void addGas(double gasToAdd){
        gasInTank=gasInTank+gasToAdd;
    }
    public void Car2Demo()
    {
        Canvas canvas=new Canvas();
        canvas.add(carImage,200,200);
    }
}
