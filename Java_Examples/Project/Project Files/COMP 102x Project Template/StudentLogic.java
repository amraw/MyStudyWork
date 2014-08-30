import java.util.Random;

import comp102x.ColorImage;
import comp102x.assignment.GameLogic;
import comp102x.assignment.GameRecord;
import comp102x.assignment.Goal;
/**
 * This Student Logic class provide method for generating the correct intermediate Football Image, updating the goal position and updating the score list of the
 * players.
 * @author(Amit Rawat)
 * @date(31/7/2014)
 */


public class StudentLogic implements GameLogic{
    /**
     * This method select the  correct image, calculate and sets its X-position, calculate and sets its Y-position, calculate and sets its Scale and return 
     * that image.
     */
    public ColorImage generateIntermediateFootballImage(ColorImage[] depthImages, int initialStep, int currentStep, int finalStep, double initialScale, double finalScale, int initialX, int finalX, int initialY, int finalY) {
        // write your code after this line
        double imageIndex,xPosition,yPosition;
        double scale;
        imageIndex=((depthImages.length-1)*(((double)(currentStep-initialStep))/(double)(finalStep-initialStep)));
        xPosition=initialX+((finalX-initialX)*(((double)(currentStep-initialStep))/((double)(finalStep-initialStep))));
        depthImages[(int)imageIndex].setX((int)xPosition);
        yPosition=initialY+((double)(finalY-initialY)*((double)(currentStep-initialStep)/((double)(finalStep-initialStep))));
        depthImages[(int)imageIndex].setY((int)Math.round(yPosition));
        scale=initialScale+((finalScale-initialScale)*((((double)(currentStep-initialStep))/((double)(finalStep-initialStep)))));
        depthImages[(int)imageIndex].setScale(scale);
        return depthImages[(int)imageIndex];
    }
    
    /**
    * This method update the positions of goal on the Canvas.
    */

    public void updateGoalPositions(Goal[][] goals) {
        // write your code after this line
        int rows=goals.length;
        int col=goals[0].length;
        int []moveGoalRow;int []moveGoalCol;
        moveGoalRow=new int[12];
        moveGoalCol=new int[12];
        int[]hitRow;int []hitCol;
        hitRow=new int[11];
        hitCol=new int[11];
        int k=0,m=0;
        
        for(int i=0;i<rows;i++)
        for(int j=0;j<col;j++)
        {
            if(goals[i][j].getType()== 2 && !goals[i][j].isHit())
            {
               moveGoalRow[k]=i;
               moveGoalCol[k++]=j;
            }
            else if(goals[i][j].isHit())
            {
                hitRow[m]=i;
                hitCol[m++]=j;
            }
        }
        if(k!=0 && m!=0)
        {
            Random randobject1=new Random();
            
            if(m<k)
            {
              int hitGoal=randobject1.nextInt(m);
              int p=hitRow[hitGoal],q=hitCol[hitGoal];
              swap1(goals,p,q);
            }
            else
            {
                int moveGoal=randobject1.nextInt(k);
                int i=moveGoalRow[moveGoal],j=moveGoalCol[moveGoal];
                swap2(goals,i,j);
            }
       }
    }
    
    /**
     * This method is use for swaping the movable goal with an empty space at row=p and Coloumn=r. It is used when
     * number of Goals hit is less than number of goal left.
     */
    
    
    public static void swap1(Goal[][]goals,int p,int r)
    {
        int row=goals.length;
        int col=goals[0].length;
        Random randobject2=new Random();
        boolean loop=true;
        int i=-1,j=-1;
        while(loop)
        {
            int choice=randobject2.nextInt(8);
            switch(choice)
            {
                case 0:
                        if((p-1)>=0)
                        {
                            if(goals[p-1][r].getType()==2 && !goals[p-1][r].isHit())
                            {
                                i=p-1;
                                j=r;
                                loop=false;
                            }
                        }
                        break;
                case 1: if((p-1)>=0 && (r+1)<col)
                        {
                            if(goals[p-1][r+1].getType()==2 && !goals[p-1][r+1].isHit())
                            {
                                i=p-1;
                                j=r+1;
                                loop=false;
                            }
                        }
                        break;
                case 2: if((r+1)<col)
                        {
                            if(goals[p][r+1].getType()==2 && !goals[p][r+1].isHit())
                            {
                                i=p;
                                j=r+1;
                                loop=false;
                            }
                        }
                        break;
                case 3:if((p+1)<row && (r+1)<col)
                        {
                            if(goals[p+1][r+1].getType()==2 && !goals[p+1][r+1].isHit())
                            {
                                i=p+1;
                                j=r+1;
                                loop=false;
                            }
                        }
                        break;
                case 4: if((p+1)<row)
                        {
                            if(goals[p+1][r].getType()==2 && !goals[p+1][r].isHit())
                            {
                                i=p+1;
                                j=r;
                                loop=false;
                            }
                        }
                        break;
                case 5: if((p+1)<row && (r-1)>=0)
                        {
                            if(goals[p+1][r-1].getType()==2 && !goals[p+1][r-1].isHit())
                            {
                                i=p+1;
                                j=r-1;
                                loop=false;
                            }
                        }
                        break;
                case 6: if((r-1)>=0)
                        {
                            if(goals[p][r-1].getType()==2 && !goals[p][r-1].isHit())
                            {
                                i=p;
                                j=r-1;
                                loop=false;
                            }
                        }
                        break;
                case 7: if((p-1)>=0 && (r-1)>=0)
                        {
                            if(goals[p-1][r-1].getType()==2 && !goals[p-1][r-1].isHit())
                            {
                                i=p-1;
                                j=r-1;
                                loop=false;
                            }
                        }
                        break;
                default:
                
            }
        }
        Goal temp=goals[p][r];
        goals[p][r]=goals[i][j];
        goals[i][j]=temp;
    }
    
    /**
     * This method is use to swapping the movable goal at position row=i and col=j with any empty or Goal which is already hit. It is used when
     * number of Goals hit is greater than number of goal left.
     */
    public static void swap2(Goal [][]goals,int i,int j)
    {
        int row=goals.length;
        int col=goals[0].length;
        Random randobject2=new Random();
        boolean loop=true;
        int p=-1,r=-1;
        while(loop)
        {
            int choice=randobject2.nextInt(8);
            switch(choice)
            {
                case 0:if((i-1)>=0)
                        {
                            if(goals[i-1][j].isHit())
                            {
                                p=i-1;
                                r=j;
                                loop=false;
                            }
                        }
                        break;
                case 1:if((i-1)>=0 && (j+1)<col)
                        {
                            if(goals[i-1][j+1].isHit())
                            {
                                p=i-1;
                                r=j+1;
                                loop=false;
                            }
                        }
                        break;
                case 2:if((j+1)<col)
                        {
                            if(goals[i][j+1].isHit())
                            {
                                p=i;
                                r=j+1;
                                loop=false;
                            }
                        }
                        break;
                case 3:if((i+1)<row && (j+1)<col)
                        {
                            if(goals[i+1][j+1].isHit())
                            {
                                p=i+1;
                                r=j+1;
                                loop=false;
                            }
                        }
                        break;
                case 4:if((i+1)<row)
                        {
                            if(goals[i+1][j].isHit())
                            {
                                p=i+1;
                                r=j;
                                loop=false;
                            }
                        }
                        break;
                case 5:if((i+1)<row && (j-1)>=0)
                        {
                            if(goals[i+1][j-1].isHit())
                            {
                                p=i+1;
                                r=j-1;
                                loop=false;
                            }
                        }
                        break;
                case 6:if((j-1)>=0)
                        {
                            if(goals[i][j-1].isHit())
                            {
                                p=i;
                                r=j-1;
                                loop=false;
                            }
                        }
                        break;
                case 7: if((i-1)>=0 && (j-1)>=0)
                        {
                            if(goals[i-1][j-1].isHit())
                            {
                                p=i-1;
                                r=j-1;
                                loop=false;
                            }
                        }
                        break;
                default:
                
            }
            
        }
        Goal temp=goals[p][r];
        goals[p][r]=goals[i][j];
        goals[i][j]=temp;
    }
    
    /**
     * This method is use for updating the High Score Records when the game ends.
     */
    public GameRecord[] updateHighScoreRecords(GameRecord[] highScoreRecords, String name, int level, int score) {
        // write your code after this line
        GameRecord newEntry=new GameRecord(name,level,score);
        boolean nameExist=false;
        int length,index=-1;
        length=highScoreRecords.length;
        GameRecord[] newRecord;
        if(length==0)
        {
            newRecord=new GameRecord[1];
            newRecord[0]=newEntry;
        }
        else
        {
            for(int i=0;i<highScoreRecords.length;i++)
            {
                String nameInRecord=highScoreRecords[i].getName();
                if(name.equals(nameInRecord))
                {
                nameExist=true;
                index=i;
                break;
                }
              }
            if(nameExist)
            {
                if(highScoreRecords[index].getScore() < score)
                {
                    highScoreRecords[index].setScore(score);
                    if(highScoreRecords[index].getLevel()!=level)
                    highScoreRecords[index].setLevel(level);
                }
                sort(highScoreRecords);
                return highScoreRecords; // Sort is needed here
            }
            else
            {
                if(length!=10)
                {
                   newRecord=new GameRecord[length+1];
                   System.arraycopy(highScoreRecords, 0, newRecord, 0, length);
                   newRecord[length]=newEntry; // Sorting in needed here
                   sort(newRecord);
                }
                else
                {
                    if(score > highScoreRecords[length-1].getScore())
                    {
                        highScoreRecords[length-1]=newEntry;
                    }
                    if(score == highScoreRecords[length-1].getScore())
                    {
                        if(level > highScoreRecords[length-1].getLevel())
                        highScoreRecords[length-1]=newEntry;
                    }
                    sort(highScoreRecords);
                return highScoreRecords;
                }
            }
        }
        return newRecord;
    }
    
    
    public static void sort(GameRecord[] records)
    {
        int largestIndex=-1;
        for(int i=0;i<records.length-1;i++)
        {
            largestIndex=i;
            for(int j=i+1;j<records.length;j++)
            {
                if(records[j].getScore()>records[largestIndex].getScore())
                {
                largestIndex=j;
                break;
                }
                else if(records[j].getScore()==records[largestIndex].getScore())
                {
                    if(records[j].getLevel()>records[largestIndex].getLevel())
                    {
                        largestIndex=j;
                        break;
                    }
                    else if(records[j].getLevel()==records[largestIndex].getLevel())
                    {
                        int k=records[j].getName().compareToIgnoreCase(records[largestIndex].getName());
                        if(k<0)
                        largestIndex=j;
                        else
                        continue;
                        break;
                    }
                }
            }
            GameRecord temp=records[i];
            records[i]=records[largestIndex];
            records[largestIndex]=temp;
        }
        
    }
}
