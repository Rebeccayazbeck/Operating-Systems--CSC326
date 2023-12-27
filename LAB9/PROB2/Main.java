import java.util.Scanner;

public class Main {
public static void main(String[] args){
	
	System.out.println("Please enter the first name: ");
	Scanner scan= new Scanner(System.in);
	String n1= scan.nextLine();
	MyThread T1 = new MyThread(10, n1);
			
	System.out.println("Please enter the second name: ");
	String n2= scan.nextLine();
	MyThread T2 = new MyThread(11, n2);
	
	System.out.println("Please enter the third name: ");
	String n3= scan.nextLine();
	MyThread T3 = new MyThread(12, n3);
	
	T1.start();
	try
	{
		T1.join();
	}
	catch(InterruptedException e1)
	{
		System.out.println("Thread interrupted!");
	}
	T2.start();
	try
	{
		T2.join();
	}
	catch(InterruptedException e1)
	{
		System.out.println("Thread interrupted!");
	}
	
	T3.start();
	try
	{
		T3.join();
	}
	catch(InterruptedException e1)
	{
		System.out.println("Thread interrupted!");
	}
	
System.out.println("\nAfter running all the threads:");
System.out.println("The length of the first name is : "+T1.getLength());
System.out.println("The length of the second name is : "+T2.getLength());
System.out.println("The length of the third name is : "+T3.getLength());

}
}

