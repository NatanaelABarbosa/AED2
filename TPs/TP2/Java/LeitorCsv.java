import java.util.Scanner;
import java.io.BufferedReader;
import java.io.FileReader;

public class LeitorCsv {
	// "C:\Users\natan\OneDrive\Documentos\Ciência da Computação - Puc Minas\1. Período\2º periodo\AEDs 2\TPs\TP2\veiculos.csv"
	public static Veiculo[] ler (String path) throws Exception {
		Veiculo[] veiculos = new Veiculo[500];
		FileReader leitorArquivo = new FileReader(path);
		BufferedReader leitor = new BufferedReader(leitorArquivo);
		
		String linha = leitor.readLine();
		linha = leitor.readLine();
		for (int i = 0; linha != null; i++) {
			veiculos[i] = new Veiculo();
			veiculos[i] = Veiculo.parseVeiculo(linha);
			
			linha = leitor.readLine();
		}
		
		leitor.close();
		return veiculos;
	}	
}

