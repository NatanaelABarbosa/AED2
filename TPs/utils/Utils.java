public class Utils {
	/**
	 * Compara se duas cadeias de caracteres sao iguais
	 *
	 * @param str1 A primeira string a ser comparada.
	 * @param str2 A segunda string a ser comparada.
	 * @return true caso forem iguais, false senao.
	 */
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
	 * Recebe uma string e retorna outra string sem caracteres repetidos
	 *
	 * @param str A string que sera copiada e modificada
	 * @return A string sem caracteres repetidos
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
	 * Recebe duas strings e verifica quantos caracteres da segunda string contem na primeira
	 * 
	 * @param str1 A string que sera comparada
	 * @param str2 A string que tera os caracteres para comparar
	 * @return a quantidade de caracteres contidos
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
}
