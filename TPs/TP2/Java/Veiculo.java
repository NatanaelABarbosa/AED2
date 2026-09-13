import java.util.Scanner;

public class Veiculo {
	private int id;
	private String marca;	
	private String modelo;
	private int ano;
	private String categoria;
	private String[] combustivel;
	private int cilindros;
	private double cilindrada;
	private String transmissao;
	private String tracao;	
	private double consumoCidade;
	private double consumoEstrada;
	private double co2;
	private boolean turbo;
	private Data dataRegistro;

	public static Veiculo parseVeiculo(String s) {
		Veiculo v = new Veiculo();
		String[] dados = s.split(",");

		v.id =             Helper.strToInt(dados[0]);
		v.marca =                  dados[1];
		v.modelo =                 dados[2];
		v.ano =            Helper.strToInt(dados[3]);
		v.categoria =              dados[4];
		v.combustivel =            dados[5].split(";");
		v.cilindros =      Helper.strToInt(dados[6]);
		v.cilindrada =     Helper.strToDouble(dados[7]);
		v.transmissao =            dados[8];
		v.tracao =                 dados[9];
		v.consumoCidade =  Helper.strToDouble(dados[10]);
		v.consumoEstrada = Helper.strToDouble(dados[11]);
		v.co2 =            Helper.strToDouble(dados[12]);
		v.dataRegistro =   Data.parseData(dados[14]);

		if (dados[13] == "true") v.turbo = true;
		else v.turbo = false;

		return v;
	}
		
	public String format() {
		String strTurbo = "";
		String strCombustivel = "";

		for (int i = 0; i < combustivel.length; i++) {
			strCombustivel += combustivel[i];
			if (i != combustivel.length-1) strCombustivel += ",";
		}

		if (turbo) strTurbo = "true";
		else strTurbo = "false";

		return String.format("[%d ## %s ## %s ## %d ## %s ## [%s] ## %d ## %f ## %s ## %s ## %f ## %f ## %f ## %s ## %s]", id, marca, modelo, ano, categoria, strCombustivel, cilindros, cilindrada, transmissao, tracao, consumoCidade, consumoEstrada, co2, strTurbo, dataRegistro.format());
	}
}

