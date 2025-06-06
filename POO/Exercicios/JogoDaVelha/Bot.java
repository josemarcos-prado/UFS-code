/*  
    Feito por:
    José Marcos Bittencourt Oliveira Prado (matrícula 202400017960), e 
    Sidnei Silva Gonçalves Junior (matricula 202400018369)
*/

import java.util.Random;

public class Bot {
    private char simbolo;
    private Random aleatorio;

    public Bot (char simbolo) {
        this.simbolo = simbolo;
        aleatorio = new Random();
    }

    public char obterSimbolo () {
        return simbolo;
    }

    public int obterLinha () {
        return aleatorio.nextInt(3);
    }

    public int obterColuna () {
        return aleatorio.nextInt(3);
    }
}
