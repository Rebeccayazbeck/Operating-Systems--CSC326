
public class ComputeAverageThread extends Thread {
	
	private int [] MyArray= new int [5];
	private double Avg;
	
	public ComputeAverageThread(int a[])
	{
		MyArray=a;
		SetAverage(MyArray);
	}
	
	public void SetAverage(int a[])
	{
		double sum=0;
		for(int i=0; i<5;i++)
			sum=sum+a[i];
		
		Avg= (double) sum/5.0;
	}

	public void run()
	{
		SetAverage(MyArray);
		System.out.println("* From Thread2 - computing the average... ");
	}
	
	public double getAvg()
	{
		return Avg;
	}
}
