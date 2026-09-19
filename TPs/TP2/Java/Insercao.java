import java.util.Scanner;

public class Insercao {
	private static void insertion (Veiculo [] arr) {
		int j = 0;
		int l = 0;
		Veiculo tmp = null;
		char ch1 = '0', ch2 = '0';
		boolean stop = false;

		for (int i = 1; i < arr.length; i++) {
			j = i-1;	
			tmp = arr[i];
			stop = false;	

			while (j >= 0 && stop == false) {
				int len1 = arr[j].getMarca().length();
				int len2 = tmp.getMarca().length();
				
				l=0;
				ch1 = arr[j].getMarca().charAt(l);
				ch2 = tmp.getMarca().charAt(l);

				if ('A' <= ch1 && ch1 <= 'Z') ch1 += 'a' - 'A';
				if ('A' <= ch2 && ch2 <= 'Z') ch2 += 'a' - 'A';
	
				if (ch1 > ch2) arr[j+1] = arr[j--];
				else if (ch1 < ch2) stop = true;
				
				l++;				
				while (ch1 == ch2 && l < len1 && l < len2) {
					ch1 = arr[j].getMarca().charAt(l);
					ch2 = tmp.getMarca().charAt(l);		

					if ('A' <= ch1 && ch1 <= 'Z') ch1 += 'a' - 'A';
					if ('A' <= ch2 && ch2 <= 'Z') ch2 += 'a' - 'A';
					
					if (ch1 > ch2) arr[j+1] = arr[j--];
					else if (ch1 < ch2) stop = true;
					l++;
				}

				if (l >= len1 || l >= len2) stop = true;
			}

			arr[j+1] = tmp;
		}

		tmp = null;
	}

	public static void main (String[] args) throws Exception {
		Veiculo[] veiculos = new Veiculo[500];
		Veiculo[] arr = new Veiculo[50];
		Scanner inp = new Scanner(System.in);
		int n = 0;

		veiculos = LeitorCsv.ler("veiculos.csv");

		n = inp.nextInt();
		for (int i = 0; n != -1; i++) {
			arr[i] = Veiculo.searchById(veiculos, n);
			n = inp.nextInt();
		}

		veiculos = null;
		insertion(arr);

		for (int i = 0; i < arr.length; System.out.println(arr[i].format()), i++);
		arr = null;
	}
}

