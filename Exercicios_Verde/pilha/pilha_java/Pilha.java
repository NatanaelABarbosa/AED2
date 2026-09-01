import java.util.Scanner;

class Pilha {
	private int arr[];
	private int n;

	public Pilha(int tamanho) {
		arr = new int[tamanho];
		n = 0;
	} //constroi a pilha com capacidade máxima igual a tamanho
	
	// FI
	public void empilhar(int x) {
		if (n < arr.length) {
			arr[n] = x;
			n++;
		}	
	} //empilha x à pilha

	public int desempilhar() {
		if (n > 0) {
			return arr[--n];
		}		
		return -1;	
	} //desempilha da pilha e retorna o elemento desempilhado

	public void mostrar() {

		if (n > 0) {
			for (int i = n-1; i >= 0; i--) {
				System.out.print("" + arr[i] + " ");
			}
		} else System.out.print("V");

		System.out.println("");
	} //imprime os elementos da pilha partindo do topo

	public boolean pesquisar(int x) { 
		boolean res = false;
		
		for (int i = 0; i < n; i++) {
			if (arr[i] == x) {res = true; i = n;}
		}

		return res;
	} //retorna true caso o elemento x esteja na pilha e false caso contrário

	public static void main(String[] args) {
		Scanner inp = new Scanner(System.in);
		char comando = '0';
		Pilha pilha = new Pilha(1);

		while (inp.hasNext()) {
			comando = inp.next().charAt(0);
			if (comando == 'C') pilha = new Pilha(inp.nextInt());
			else if (comando == 'E') pilha.empilhar(inp.nextInt());
			else if (comando == 'D') System.out.println(pilha.desempilhar());
			else if (comando == 'M') pilha.mostrar();
			else {
				if (pilha.pesquisar(inp.nextInt())) {
					System.out.println("S");
				} else System.out.println("N");
			}
		}
	}
}

