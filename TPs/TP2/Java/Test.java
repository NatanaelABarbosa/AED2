
public class Test {
		public static void main (String[] args) throws Exception{
		Veiculo[] veiculos = new Veiculo[500];

		veiculos = LeitorCsv.ler("veiculos.csv");
		for (int i = 0; i < 500; i++) {
			System.out.println(veiculos[i].format() + "\n");
		}
	}
}

