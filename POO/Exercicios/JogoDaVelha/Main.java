/*  
    Feito por:
    José Marcos Bittencourt Oliveira Prado (matricula 202400017960), e 
    Sidnei Silva Gonçalves Junior (matricula 202400018369)
*/

import java.util.Random;

public class Main {
    public static void main(String[] args) {
        Jogador jogador = new Jogador('X');
        Bot bot = new Bot('O');
        Tabuleiro tab = new Tabuleiro();
        Random rand = new Random();

        //se for par, jogador, se for impar, bot
        int vez = rand.nextInt(2);

        while (!tab.acabou()) {
            if (vez%2 == 0) {
                System.out.print("\n" + tab.viraString());
                System.out.println("\nSua vez");
                while(!tab.jogar(jogador.obterLinha(), jogador.obterColuna(), jogador.obterSimbolo()))
                    System.out.println("Posicoes invalidas");
                vez++;
            }
            else {
                System.out.print("\n" + tab.viraString());
                System.out.println("\nVez do oponente");
                boolean valido;
                do{
                    valido = tab.jogar(bot.obterLinha(), bot.obterColuna(), bot.obterSimbolo());
                } while (!valido);
                vez++;
            }
        }

        System.out.print("\n" + tab.viraString());
        if (tab.existeVencedor()){
            if (vez%2 == 0)
                System.out.println("\nO oponente venceu...");
            else 
                System.out.println("\nParabens! Voce venceu!");
        }
        else 
            System.out.println("\nEmpate, tente novamente...");
    }
}