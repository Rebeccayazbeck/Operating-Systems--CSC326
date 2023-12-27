
public class MyThread extends Thread {
	String function;
	int array[];
	double res;

	public double getRes() {
		return res;
	}

	public MyThread(String function, int[] array, double res) {
		super();
		this.function = function;
		this.res = res;
		this.array = array;
	}

	public void run() {
		int max, min;
		double average = 0;
		if (this.function.equals("MAX")) {
			max = array[0];
			for (int i = 1; i < array.length; i++)
				if (array[i] > max)
					max = array[i];
			res = max;
		} else if (this.function.equals("AVERAGE")) {
			for (int o = 0; o < array.length; o++)
				average += array[o];
			res = average/array.length;
		} else if (this.function.equals("MIN")) {
			min = array[0];
			for (int i = 1; i < array.length; i++)
				if (array[i] < min)
					min = array[i];
			res = min;
		} else {
			System.out.println(Thread.currentThread().getName() + " wrong function name");
		}
	}
}
