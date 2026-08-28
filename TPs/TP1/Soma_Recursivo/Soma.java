/**
 * @author Natanael Barbosa
 */
import java.util.Scanner;

public class Soma {
	/**
	 * Recebe uma string e retorna a soma dos numeros deles, caso sejam numeros. Caso tenham letras, a soma nao e' alterada. O parametro i e' o iterador da string.
	 */
	public static int sum(String str, int i) {
		int len = str.length();
		int res = 0;

		if (i < len) {
			if ('0' <= str.charAt(i) && str.charAt(i) <= '9') {
				res = (int)(str.charAt(i) - '0');
				return res += sum(str, i+1);	
			}
			return sum(str, i+1);
		}
		return res;
	}

	public static void main(String[] args) {
		Scanner inp = new Scanner(System.in);
		String str = "";
		int res = 0;

		str = inp.nextLine();
		while (inp.hasNext()) {
			res = sum(str, 0);

			System.out.println(res);
				
			str = inp.nextLine();
		}
		
		res = sum(str, 0);
		System.out.print(res);
		
		inp.close();
	}
}
