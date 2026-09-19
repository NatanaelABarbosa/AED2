public class Data {
	private int ano;
	private int mes;
	private int dia;

	public static Data parseData(String str) {
		Data res = new Data();
		String [] dataStr = str.split("-");

		res.ano = Helper.strToInt(dataStr[0]);
		res.mes = Helper.strToInt(dataStr[1]);
		res.dia = Helper.strToInt(dataStr[2]);

		return res;
	}

	public String format() {
		return String.format("%02d/%02d/%d", dia, mes, ano);
	}
}

