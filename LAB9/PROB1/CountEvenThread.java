
public class CountEvenThread extends Thread {
	
	private int [] MyArray= new int [5];
	private int Count;
	
	public CountEvenThread(int a[])
	{
		MyArray=a;
		
	}

	public void run()
	{
		System.out.println("-2- From Thread2 - counting the even integers... ");
        Count=0;
        for(int i=0; i<5;i++)
            {
                if(MyArray[i]%2==0)
                    Count=Count+1;
            }
        System.out.println("-2- From Thread2 - The count of even integers is: "+Count);
	}
	
	public int getCount()
	{
		return Count;
	}
}
