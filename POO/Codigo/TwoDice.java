import java.util.*;

public class TwoDice {
    public static void main (String [] args) {
        double [] rates = new double[13];
        Scanner keyboard = new Scanner (System.in);

        String texto = "Ola, tudo bem?\n";

        System.out.print(texto);
        System.out.print("Forneca o numero de tentativas: ");
        int rounds = keyboard.nextInt();

        for (int i = 1; i <= rounds; i++) {
            int pos =  (int) (Math.random() * 6) + (int) (Math.random() * 6) + 2;
            rates[pos]++;
        }

        for (int pos = 2; pos <= 12; pos++) {
            rates[pos] = rates[pos] * 100 / rounds;
        }

        for (int pos = 2; pos <= 12; pos ++) {
            System.out.printf("%2d %6.2f%%%n", pos, rates[pos]);
        }
    }
}