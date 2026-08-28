import java.util.Scanner;

public class Espelho {
	public static String gerarSequencia(Scanner input, int a, int b) {
		String sequencia = "";

		for (int i = a; i <= b; i++) 
			sequencia += i;
		
		int n = sequencia.length();

		for (int i = 0; i < n; i++) 
			sequencia += sequencia.charAt(n-i-1);

		return sequencia;
	}

	public static void main (String[] args) {
		Scanner input = new Scanner(System.in);
		
		while (input.hasNext()) {
			int a = input.nextInt();
			int b = input.nextInt();

			System.out.println(gerarSequencia(input, a, b));
		}
		input.close();
	}
}