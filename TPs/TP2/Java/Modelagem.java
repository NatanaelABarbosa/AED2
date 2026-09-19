import java.util.Scanner;

public class Modelagem {
		public static void main (String[] args) throws Exception{
		Veiculo[] veiculos = new Veiculo[500];
		Scanner inp = new Scanner(System.in);

		int n = inp.nextInt();
		veiculos = LeitorCsv.ler("veiculos.csv");
		while (n != -1) {
			for (int i = 0; i < 500; i++) {
				if (n == veiculos[i].getId()) System.out.println(veiculos[i].format());
			}
			n = inp.nextInt();
		}
	}
}

