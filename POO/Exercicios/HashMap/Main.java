/*Alunos: José Marcos Bittencourt Oliveira Prado
 * Sidnei Silva Gonçalves Junior
 */

import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        try {
            Scanner fileReader = new Scanner(new File("ap04.md"));
            Map<String, Integer> dicionario = new HashMap<>();

            while(fileReader.hasNext()){
                String linha = fileReader.nextLine();
                String[] palavras = linha.split(" ");

                for (String pal : palavras){
                    if (dicionario.containsKey(pal)){
                        int count = (dicionario.get(pal).intValue()) + 1;
                        Integer contagem = Integer.valueOf(count);
                        dicionario.replace(pal, contagem);
                    }
                    else {
                        dicionario.put(pal, 1);
                    }
                }
            }

            ArrayList<String> palavras = new ArrayList<>();
            ArrayList<Integer> contagem = new ArrayList<>();
            for (Map.Entry<String, Integer> item : dicionario.entrySet()){
                palavras.add(item.getKey());
                contagem.add(item.getValue());
            }
            System.out.println("Ordem Alfabética: \n");
            palavras.sort(null);
            for (String pal : palavras){
                System.out.println("Palavra: " + pal + "    Quantidade: " + dicionario.get(pal));
            }

            System.out.println("\nOrdem Decrescente da contagem: \n");
            contagem.sort(Collections.reverseOrder());
            for (Integer num : contagem){
                String palavra = "";
                for (Map.Entry<String, Integer> item : dicionario.entrySet()){
                    if (item.getValue().equals(num)) {
                        palavra = item.getKey();
                    }
                }
                System.out.println("Palavra: " + palavra + "    Quantidade: " + num);
            }
            
        } catch (FileNotFoundException e) {
            System.out.println("Num deu");
        }


    }
}