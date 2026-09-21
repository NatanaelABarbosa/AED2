import java.util.Scanner;

class Lista {
	private int n;
	private Veiculo [] arr;

	Lista(int x) {
		arr = new Veiculo[x];
		n = 0;
	}

	public void inserirInicio(Veiculo v) {
		if (n < arr.length) {
			for (int i = n; i > 0; i--) arr[i] = arr[i-1];
			arr[0] = v; n++;
		}
	}

	public void inserirFim(Veiculo v) {
		if (n < arr.length) arr[n++] = v;	
	}

	public void inserir(int pos, Veiculo v) {
		if (n < arr.length && pos >= 0 && pos <= n) {
			if (pos == n) inserirFim(v);
			else if (pos == 0) inserirInicio(v);
			else {
				for (int i = n; i > pos; i--) arr[i] = arr[i-1];
				arr[pos] = v; n++;
			}
		}
	}

	public Veiculo removerInicio() {
		Veiculo res = null;
	
		if (n > 0) {
			res = arr[0]; n--;
			for (int i = 0; i < n; i++) arr[i] = arr[i+1];
		}

		return res;
	}

	public Veiculo removerFim() {
		Veiculo res = null;

		if (n > 0) res = arr[--n];
	
		return res;
	}

	public Veiculo remover(int pos) {
		Veiculo res = null;

		if (n > 0 && pos >= 0 && pos < n) {
			if (pos == 0) res = removerInicio();
			else if (pos == n-1) res = removerFim();
			else {
				res = arr[pos]; n--;
				for (int i = pos; i < n; i++) arr[i] = arr[i+1];
			}
		}

		return res;	
	}

	public void mostrar() {
		for (int i = 0; i < n; i++) System.out.println(arr[i].format());
	}
}

public class ListaSequencial {	
	public static void main (String[] args) throws Exception{
		Scanner inp = new Scanner(System.in);
		Veiculo[] veiculos = LeitorCsv.ler("veiculos.csv");
		Lista lista = new Lista(500);
		int n = 0;
		
		n = inp.nextInt();
		while (n != -1) {
			lista.inserirFim(Veiculo.searchById(veiculos, n));
			n = inp.nextInt();	
		}

		n = inp.nextInt();
		Veiculo vtmp = null;
		for (int i = 0; i < n; i++) {
			String c = inp.next();
			if (c.charAt(0) == 'I') {
				if (c.charAt(1) == 'I') lista.inserirInicio(Veiculo.searchById(veiculos, inp.nextInt()));
				else if (c.charAt(1) == 'F') lista.inserirFim(Veiculo.searchById(veiculos, inp.nextInt()));
				else lista.inserir(inp.nextInt(), Veiculo.searchById(veiculos, inp.nextInt()));
			} else {
				
				if (c.charAt(1) == 'I') {
					vtmp = lista.removerInicio();
					System.out.println("(R)" + vtmp.getMarca() + " " + vtmp.getModelo());
				}
				else if (c.charAt(1) == 'F') {
					vtmp = lista.removerFim();
					System.out.println("(R)" + vtmp.getMarca() + " " + vtmp.getModelo());
				}
				else {
					vtmp = lista.remover(inp.nextInt());
					System.out.println("(R)" + vtmp.getMarca() + " " + vtmp.getModelo());
				}
			}
		}

		lista.mostrar();
	}
}

