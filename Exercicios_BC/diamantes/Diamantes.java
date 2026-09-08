import java.io.IOException;
import java.util.Scanner;

public class Diamantes {
	public static void main(String[] args) throws IOException {
 		Scanner inp = new Scanner(System.in);
		int n = inp.nextInt();
		inp.nextLine();
		String str = "";
		char [] cleaned = new char[1000];
		
		for (int i = 0; i < n; i++) {
			int k = 0; int res = 0;
			str = inp.nextLine();
			int len = str.length();
			char c = '0';

			for (int j = 0; j < len; j++) 
			{ c = str.charAt(j); if (c == '<' || c == '>') cleaned[k]=c; k++; }

			for (int j = 0; j < cleaned.length-1; j++) {
				c = cleaned[j]; 	
				if (c == '<') {
					for (k = j+1; k < cleaned.length; k++) {
						if (cleaned[k] == '>') {
							res++; 
							cleaned[k] = cleaned[j] = '*';	
							k = cleaned.length;
						}
					}
				}
			}
			
			System.out.println(res);
			cleaned = new char[1000];
		}
		inp.close();
	}
}

