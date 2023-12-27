import java.util.Scanner;

public class Main {
public static void main(String[] args){
	
    int [] A= new int [5];
    FillArrayThread Thread1= new FillArrayThread();
	
	System.out.println("*** From the main: Thread 1 started...");
	Thread1.start();
	try
	{
		Thread1.join();
	}
	catch(InterruptedException e1)
	{
		System.out.println("Thread interrupted!");
	}

    System.out.println("*** From the main: Thread 1 terminated...");
	
    A=Thread1.getA();
    
    System.out.println("*** From the main: The array elements are as follows: ");
    for(int i=0; i<5;i++)
    {
        System.out.print(A[i]+" ");
    }
    System.out.println(" ");
    
    
    CountEvenThread Thread2= new CountEvenThread(A);
    Thread2.start();
    try
    {
        Thread2.join();
    }
    catch(InterruptedException e1)
    {
        System.out.println("Thread2 interrupted!");
    }
    
    System.out.println("*** From the main: Thread 2 terminated...");
    int CountMain= Thread2.getCount();
    System.out.println("*** From the main: The count of even integers is: "+ CountMain);
    
    
    PercentageEvenThread Thread3= new PercentageEvenThread(CountMain);
    Thread3.start();
    try
    {
        Thread3.join();
    }
    catch(InterruptedException e1)
    {
        System.out.println("Thread3 interrupted!");
    }
    
    System.out.println("*** From the main: Thread 3 terminated...");
    double Perc= Thread3.getPer();
    System.out.println("*** From the main: The percentage of even integers is: "+ Perc +"%");
    

}
}

