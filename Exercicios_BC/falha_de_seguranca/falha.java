import java.util.Scanner;

public class falha {
	private static boolean contains(String str1, String str2) {
		boolean res = false;
		String tmp = "";

		if (str1.length() >= str2.length()) {
			for (int i = 0; i <= str1.length() - str2.length(); i++) {
				for (int j = i; j < str2.length() + i; j++) tmp += str1.charAt(j);
		
				if (str2.equals(tmp)) 
				{ res = true; i = str1.length(); }
				else tmp = "";
			}
		}

		return res;
	}

	public static void main (String [] args){
		Scanner inp = new Scanner(System.in);
		int n = inp.nextInt();
		int res = 0;
		inp.nextLine();
		String[] senhas = new String[n];

		for (int i = 0; i < n; i++) senhas[i] = inp.nextLine();
	
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i != j) 
				{ if (contains(senhas[i], senhas[j])) res++; }
			}
		}

		System.out.println(res);
	}
}

