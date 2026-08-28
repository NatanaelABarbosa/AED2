import java.util.Scanner;

public class Radix {
	public static void main (String[] args) {
		Scanner inp = new Scanner(System.in);
		int[] arr = new int[inp.nextInt()];
		int[] copy = new int[arr.length];
		int maior = 0;
		int ind = 0;
		int div = 1;
		int[] aux = new int[10];
		
		arr[0] = inp.nextInt();
		maior = arr[0];
		for (int i = 1; i < arr.length; i++) {
			arr[i] = inp.nextInt();
			if (arr[i] > maior) maior = arr[i];
		}
		
		int tmp = maior;
		while (tmp > 0) { tmp/=10; ind++; }

		int new_arr[] = new int[arr.length];
		
		for (int j = 0; j < ind; j++) {
			for(int i = 0; i < aux.length; aux[i] = 0, i++);
			for(int i = 0; i < arr.length; aux[(arr[i]/div)%10]++, i++);
			for(int i = 1; i < aux.length; aux[i]+=aux[i-1], i++);
			for (int i = arr.length-1; i >= 0; copy[--aux[(arr[i]/div)%10]] = arr[i], i--);
			for (int i = 0; i < arr.length; arr[i]=copy[i], i++);
			div*=10;
		}

		for(int i = 0; i < copy.length; System.out.printf("%d. %d\n", i, copy[i]), i++);


		inp.close();
	}
}

