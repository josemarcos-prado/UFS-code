import java.util.Scanner;

public class Jogador {
    private char simbolo;
    private Scanner teclado;

    public Jogador (char simbolo) {
        this.simbolo = simbolo;
        teclado = new Scanner(System.in);
    }

    public char obterSimbolo () {
        return simbolo;
    }

    public int obterColuna () {
        System.out.print("Digite a coluna em que quer jogar: ");
        return teclado.nextInt();
    }

    public int obterLinha () {
        System.out.print("Digite a linha em que quer jogar: ");
        return teclado.nextInt();
    }
}
