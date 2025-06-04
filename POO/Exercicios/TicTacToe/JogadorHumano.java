import java.util.Scanner;

public class JogadorHumano {
    private char simbolo;
    private Scanner teclado;

    public JogadorHumano (char simbolo) {
        teclado = new Scanner(System.in);
        this.simbolo = simbolo;
    }

    public char obterSimbolo () {
        return simbolo;
    }

    public int obterLinha () {
        System.out.print("Digite a linha: ");
        return teclado.nextInt();
    }

    public int obterColuna () {
        System.out.print("Digite a coluna: ");
        return teclado.nextInt();
    }
}