/**
 * @author Natanael Barbosa
 */
import java.util.Scanner;

public class Senha {
	public static boolean compare(String str1, String str2) {
		boolean res = false;

		if (str1.length() == str2.length()) {
			res = true;
			for (int i = 0; i < str1.length(); i++) {
				res = res && str1.charAt(i) == str2.charAt(i);
			}
		}
		return res;
	}

	/**
	 * Recebe uma string e inicializa um vetor com 4 indices. Caso a string (senha) tenha mais de 8 caracteres, comeca a itera-la e soma na primeira posição do array se houver uma letra minuscula, na segunda posicao caso tenha uma maiuscula, na terceira se houver numeros e na quarta caso houver caracteres especiais. Retorna true se todas as posicoes do vetor forem maior que 0.
	 */
	public static boolean verify(String str) {
		boolean res = false;
		int[] arr = new int[4];
			
		if (str != null && str.length() >= 8) {
			for (int i = 0; i < 4; arr[i] = 0, i++);
			
			for (int i = 0; i < str.length(); i++) {
				if ('a' <= str.charAt(i) && str.charAt(i) <= 'z' && arr[0] == 0) arr[0]++;
				else if ('A' <= str.charAt(i) && str.charAt(i) <= 'Z' && arr[1] == 0) arr[1]++;
				else if ('0' <= str.charAt(i) && str.charAt(i) <= '9' && arr[2] == 0) arr[2]++;
				else if (!('a' <= str.charAt(i) && str.charAt(i) <= 'z') &&
					 !('A' <= str.charAt(i) && str.charAt(i) <= 'Z') &&
					 !('0' <= str.charAt(i) && str.charAt(i) <= '9') &&
					 arr[3] == 0) arr[3]++; 	
			}
			
			res = true;
			for (int i = 0; i < 4; res = res && arr[i] > 0, i++);
		}


		return res;
	}

	public static void main (String[] args) {
		Scanner inp = new Scanner(System.in);
		String res = "";		

		String password = inp.nextLine();
		while (!compare(password, "FIM")) {	
			if (verify(password)) System.out.println("SIM");
			else System.out.println("NAO");	
			password = inp.nextLine();
		}

		inp.close();
	}
}
