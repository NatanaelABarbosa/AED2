/**
 * @author Natanael Barbosa
 */

import java.util.Scanner;
import java.util.Random;

public class Aleatorio {
	private static Random gerador = new Random(4);

	private static boolean compare(String str1, String str2) {
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
	 * Retorna um caractere entre 'a' e 'z' somando 'a' com o resto da divisão de um número "aleatório" e convertendo para caractere.
	 */
	private static char random_lowercase() {
		return (char)(('a' + (Math.abs(gerador.nextInt())%26)));
	}

	/**
	 * Recebe uma string e percorre-a. Os caracteres sao adicionados numa nova string e caso o caractere da string seja igual o caractere aleatorio selecionado, adiciona, ao inves do caractere da string, o novo caractere.
	 */
	private static String Aleatoriezar (String str) {
		char ch = random_lowercase();
		char new_ch = random_lowercase();
		String new_str = "";

		for (int i = 0; i < str.length(); i++) {
			if (str.charAt(i) == ch) {
				new_str += new_ch; 
			} else {
				new_str += str.charAt(i);
			}
		}

		return new_str;
	}

	public static void main (String[] args) {
		Scanner inp = new Scanner(System.in);
				
		String str = inp.nextLine();
		while (!compare(str, "FIM")) {
			String new_str = Aleatoriezar(str);

			System.out.println(new_str);
			str = inp.nextLine();
		}
		inp.close();	
	}
}

