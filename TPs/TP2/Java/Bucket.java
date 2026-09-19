import java.util.Scanner;

public class Bucket {
	private static void insertion (Veiculo [] arr, int n) {
		int j = 0;
		Veiculo tmp = null;

		for (int i = 1; i < n; i++) {
			j = i-1;	
			tmp = arr[i];

			while (j >= 0 && arr[j].getCilindrada() > tmp.getCilindrada()) arr[j+1] = arr[j--];
			
			arr[j+1] = tmp;
		}

		tmp = null;
	}

	public static void main (String[] args) throws Exception{
		Scanner inp = new Scanner(System.in);
		Veiculo[] veiculos = new Veiculo[500];
		Veiculo[] arr      = new Veiculo[500];
		int i = 0, x = 0;

		veiculos = LeitorCsv.ler("veiculos.csv");
		x = inp.nextInt();

		for (i = 0; x != -1; i++) {
			arr[i] = Veiculo.searchById(veiculos, x);
			x = inp.nextInt();
		}

		int bucket = 0;

		int inds[] = new int[10];
		for (int j = 0; j < 10; inds[j] = 0, j++);

		Veiculo[][] buckets = new Veiculo[10][i];
		for (int j = 0; j < i; j++) buckets
					[(int)arr[j].getCilindrada()%10]
					[inds[(int)arr[j].getCilindrada()%10]++] 
						= arr[j];

		for (int j = 0; j < 10; j++) insertion(buckets[j], inds[j]);	

		int cont = 0;
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < inds[j]; k++) arr[cont++] = buckets[j][k]; 
		}

		for (int j = 0; j < i; j++) System.out.println(arr[j].format());		
		inp.close();
	}
}
