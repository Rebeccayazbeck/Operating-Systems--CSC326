import java.util.Scanner;

public class MyArrayThread extends Thread{

	public void run()
	{
		int [] A= new int [5];
		Scanner scan= new Scanner(System.in);
		System.out.println("**From Thread1- Please enter 5 integers to fill the array: ");
		for(int i=0; i<5;i++)
		{
			A[i]= scan.nextInt();
		}
		
		System.out.println("** From Thread1- The array elements are as follows: ");
		for(int i=0; i<5;i++)
		{
			System.out.print(A[i]+" ");
		}
		System.out.println(" ");

		System.out.println("\n** From Thread1- Starting Thread 2 ");
		ComputeAverageThread Thread2= new ComputeAverageThread(A);
		Thread2.start();
		try
		{
			Thread2.join();
		}
		catch(InterruptedException e1)
		{
			System.out.println("Thread2 interrupted!");
		}
		
		System.out.println("** From Thread1- Thread 2 terminated... \n");
		
		System.out.println("** From Thread1- The average is: "+ Thread2.getAvg());
	}

}
