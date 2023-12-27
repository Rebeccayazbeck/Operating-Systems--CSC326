import java.util.Scanner;

public class FillArrayThread extends Thread{
    
    private int [] A= new int [5];
    
    public void run()
    {
        Scanner scan= new Scanner(System.in);
        System.out.println("-1- From Thread1- Please enter 5 integers to fill the array: ");
        for(int i=0; i<5;i++)
        {
            A[i]= scan.nextInt();
        }
        
        System.out.println("-1- From Thread1- The array elements are as follows: ");
        for(int i=0; i<5;i++)
        {
            System.out.print(A[i]+" ");
        }
        System.out.println(" ");
        
    }
    
    public int[] getA()
    {
        return A;
    }
}
