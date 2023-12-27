import java.util.Scanner;

public class Main {
public static void main(String[] args){
	
	MyArrayThread Thread1= new MyArrayThread();
	
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
	
}
}

