public class Helper {
	public static int strToInt(String str) {
		int res = 0;
		int fat = 1;

		for (int i = str.length()-1; i >= 0; i--) {
			res += ((int)str.charAt(i)-'0') * fat;
			fat*=10;
		}

		return res;
	}	

	public static double strToDouble(String str) {
		double res = 0.0;
		int fat = 1;
		int dot = 0;
		double fat_decimal = 1.0;
		
		while(str.charAt(dot) != '.') dot++;

		for (int i = dot - 1; i >= 0; i--) {
			res += ((int)str.charAt(i) - '0') * fat;
			fat*=10;
		}

		for (int i = dot + 1; i < str.length(); i++) {
			fat_decimal /= 10;
			res += ((int)str.charAt(i) - '0') * fat_decimal;
		}	
	
		return res;
	}
}

