
/**
 * Write a description of class array_error here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class GameRecord
{
    String name;
    int level;
    int score;
    
    public GameRecord(String name,int level,int score)
    {
        this.name=name;
        this.level=level;
        this.score=score;
    }
    
    String getName()
    {
        return this.name;
    }
    
    int getLevel()
    {
        return this.level;
    }
    
    int getScore()
    {
        return this.score;
    }
    
    void setScore(int score)
    {
        this.score=score;
    }
    
    void setLevel(int level)
    {
        this.level=level;
    }
    
    void setName(String name){
        this.name=name;
    }
    
    public static GameRecord[] updateHighScoreRecords(GameRecord[] highScoreRecords, String name, int level, int score) {
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
                highScoreRecords[index].setScore(score);
                if(highScoreRecords[index].getLevel()!=level)
                highScoreRecords[index].setLevel(level);
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
                    for(int i=0;i<length;i++)
                    {
                    if(score >= highScoreRecords[i].getScore())
                    {
                        int j=-1;
                        if(score == highScoreRecords[i].getScore())
                        {
                            if(level>highScoreRecords[i].getLevel())
                            j=i;
                            else
                            j=i+1;
                        }
                        while(j<length-1)
                        {
                            highScoreRecords[j+1]=highScoreRecords[j];
                            j++;
                        }
                        highScoreRecords[i]=newEntry;
                    }
                }
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
    
    public static void main(String []args){
        GameRecord [] newRecord=new GameRecord[3];
        String name1=new String("Sam");
        String name2=new String("Ram");
        String name3=new String("Shyam");
        newRecord[0]=new GameRecord(name1,1,21);
        newRecord[1]=new GameRecord(name2,1,15);
        newRecord[2]=new GameRecord(name3,1,10);
        String name=new String("Tan");
        GameRecord []record=updateHighScoreRecords(newRecord,name2,2,21);
        for(int i=0;i<record.length;i++)
        System.out.println(""+record[i].name+" "+record[i].level+" "+record[i].score);
    
    }
}
