
public class MyThread extends Thread{
	
	private int ID;
	private String name;
	private int Len;
	
	public MyThread(int id, String n)
	{
		ID= id;
		name= n;
		Len=name.length();
	}
	
	public void run()
	{
		System.out.println("Hello "+ name+ "! I am thread "+ ID+ " counting the length of your name..");
	}
	
	public int getLength()
	{
		return Len;
	}

}
