/**
 * @author Natanael Barbosa
 */
import java.util.Scanner;

public class Is {
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
	 * Recebe duas strings e retorna quantos caracteres da segunda string contem na primeira. Tira-se as repeticoes dos caracteres na segunda string para nao contar o mesmo caractere mais de uma vez.
	 */
	private static int containsAnyChar(String str1, String str2) {
		int res = 0;
		
		if (str1 != null && str2 != null) {
			String cleaned_str = clean(str2);	
			for (int i = 0; i < cleaned_str.length(); i++) {			
				for (int j = 0; j < str1.length(); j++) {
					if (str1.charAt(j) == cleaned_str.charAt(i)) res++;
					if (res == str1.length()) { j = str1.length(); i = cleaned_str.length();}
				}
			}	
		}
		return res;
	}

	/**
	 * Recebe uma string e retorna outra string sem caracteres repetidos
	 */
	private static String clean(String str) {
		String res = "";
		boolean repeated = false;

		if (str != null) {
			int len = str.length();
			for (int i = 0; i < len; i++) {
				for (int j = i+1; j < len; j++) {
					if (str.charAt(i) == str.charAt(j)) { 
						repeated = true; j=len;
					}
				}
				if (!repeated) { 
					res+=str.charAt(i); 
				}
				
				repeated = false;
			}
		}
		return res;
	}

	/**
	 * Recebe uma string e verifica se todos os seus caracteres sao vogais, retornando true para apenas vogais e false senao.
	 */
	private static boolean isOnlyVowels(String str) {
		boolean res = false;
		int qtyVowels = 0;
		String vowels = "aeiouAEIOU";

		qtyVowels = containsAnyChar(str, vowels);
		if (qtyVowels == str.length() && str.length() != 0) res = true; 

		return res;
	}

	/**
	 * Igual a isOnlyVowels, mas para consoantes
	 */
	private static boolean isOnlyConsonants(String str) {
		boolean res = false;
		int qtyConsonants = 0;
		String consonants = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";

		qtyConsonants = containsAnyChar(str, consonants);
		if (qtyConsonants == str.length() && str.length() != 0) res = true; 

		return res;

	}
	
	/**
	 * Igual a isOnlyVowels, mas para inteiros
	 */
	private static boolean isInteger(String str) {
		boolean res = false;
		int qtdInts = 0;
		String ints = "1234567890";

		qtdInts = containsAnyChar(str, ints);
		if (qtdInts == str.length() && str.length() != 0) res = true; 

		return res;
	}

	/**
	 * Igual a isInteger, mas permitindo um '.' ou ','
	 */
	private static boolean isReal(String str) {
		boolean res = false;
		int qtdNums = 0;
		int dots = 0;
		String nums = "1234567890.,";
 
		qtdNums = containsAnyChar(str, nums);

		if (qtdNums == str.length() && str.length() != 0 && res == false) {
			res = true;
			for (int i = 0; i < str.length(); i++) {
				if (str.charAt(i) == '.' || str.charAt(i) == ',') dots++;
				if (dots > 1) { i = str.length(); res = false; }
			}
		}
		return res;
	}

	public static void main (String[] args) {
		Scanner inp = new Scanner(System.in);
		
		String str = inp.nextLine();

		while (!compare(str, "FIM")) {
			if (isOnlyVowels(str)) System.out.print("SIM "); else System.out.print("NAO ");	
			if (isOnlyConsonants(str)) System.out.print("SIM "); else System.out.print("NAO ");
			if (isInteger(str)) System.out.print("SIM "); else System.out.print("NAO ");
			if (isReal(str)) System.out.println("SIM"); else System.out.println("NAO");
	
			str = inp.nextLine();
		}
		inp.close();
	}
}

