/**
 * @author Natanael Barbosa
 */
import java.util.Scanner;

public class Inverter {
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
	 * Recebe uma string e adiciona o valor do indice n-i-1 na posicao i da segunda string. O valor i passado por parametro é o iterador. A funcao retorna o valor adicionado em res e persiste as modificações passando res por parametro.
	 */
	public static String invert(String str, String res, int i) {
		int len = str.length();

		if (i < len) {
			res += str.charAt(len-i-1);
			return invert(str, res, i+1);
		}

		return res;
	}

	public static void main(String[] args) {
		Scanner inp = new Scanner(System.in);
		String str = "";
		String res = "";
		
		str = inp.nextLine();
		while (!compare(str, "FIM")) {
			res = invert(str, res, 0);
			System.out.println(res);
			str = inp.nextLine();
			res = "";
		}

		inp.close();
	}
}
