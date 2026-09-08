import java.util.Scanner;
import java.io.IOException;
 
public class Parenteses { 
	private static boolean verify(String str) {
		boolean res = false;
		char tmp[] = new char[1000];
		int j = 0;
		int n = 0;
		char c = '0';
		
		for (int i = 0; i < str.length(); i++) {
			c = str.charAt(i);
			if (c == '(' || c == ')') tmp[j++] = c;
		}

		if (j % 2 == 0) {
			for (int i = 0; i < j; i++) {
				if (tmp[i] == '(') {
					for (int k = i+1; k < j; k++) 
						if (tmp[k] == ')') 
						{ tmp[i] = tmp[k] = '*'; n+=2; k = j; }		
				}
			}

			if (n==j) res = true;
		}

		return res;
	}	

	public static void main(String[] args) throws IOException {
		Scanner inp = new Scanner(System.in);
		String str = "";

		while (inp.hasNext()) {
			str = inp.nextLine();
			if (verify(str)) System.out.println("correct");
			else System.out.println("incorrect");	
		}
	}
}
