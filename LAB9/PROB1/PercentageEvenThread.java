
public class PercentageEvenThread extends Thread {
    
    
    private int Count;
    private double Per;
    
    public PercentageEvenThread(int c)
    {
        Count=c;
        
    }

    public void run()
    {
        System.out.println("-3- From Thread3 - counting the percentage of even integers... ");
        Per=Count/5.0;
        System.out.println("-3- From Thread3 - The percentage of even integers is: "+Per);
    }
    
    public double getPer()
    {
        return Per;
    }
}

