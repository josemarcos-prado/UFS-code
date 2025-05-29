import java.util.Scanner;

public class ContaLetras {
    public static void main (String [] args) {
        Scanner teclado =  new Scanner(System.in);
        System.out.print("Escreva o texto: ");
        String frase = teclado.nextLine();

        int [] alfabeto = new int[26];
        String fraseMin = frase.toLowerCase();
        int tamanho = frase.length();

        for (int i = 0; i < tamanho; i++) {
            int index = fraseMin.charAt(i) - 'a';
            if (index >= 0 && index <= 25) alfabeto[index]++;
        }

        for (int i = 0; i < alfabeto.length; i++) {
            if (alfabeto[i] > 0) System.out.printf("Letra %c: %d vezes\n", (char) (i + 'a'), alfabeto[i]);
        }
    }
}