/**
 * @author Natanael Barbosa
 */
import java.util.Scanner;

public class Cesar {
	/**
	 * Criptografa uma string usando a cifra de cesar (na tabela ASCII) adicionando, para cada caractere, um valor inteiro cod.
	 */
	public static String cifrar(String str, int cod) {	
		String new_str = "";

		for (int i = 0; i < str.length(); i++) {
			int ch = (int) str.charAt(i); 
			char new_ch = (char)(ch+cod);
			
			new_str += new_ch;		
		}
		
		return new_str;
	}
	
	public static boolean compare(String str1, String str2) {
		boolean res = false;

		if (str1.length() == str2.length() && (str1 != null && str2 != null)) {
			res = true;
			for (int i = 0; i < str1.length(); i++) {
				res = res && str1.charAt(i) == str2.charAt(i);
			}
		}

		return res;
	}

	public static void main(String[] args) {
		Scanner inp = new Scanner(System.in);
		String new_str = "";

		String str = inp.nextLine();
		while (!compare(str, "FIM")) {
			new_str = cifrar(str, 3);	
			System.out.println(new_str);
			str = inp.nextLine();
		}
		inp.close();
	}
}

