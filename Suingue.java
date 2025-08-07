import java.awt.*;
import java.awt.event.*;
import java.io.File;
import java.io.FileNotFoundException; // pro Scanner
import java.util.*;
import javax.swing.*;

//VAMOS FAZER UMA JANELA COM JAVA SUINGUE, QUEREMOS UMA AREA DE TEXTO PARA DIGITAR O NOME DO ARQUIVO, UM BOTAO PARA LER O ARQUIVO E
//UMA AREA PRA BOTAR O TEXTO LIDO DO ARQUIVO.

public class Suingue extends JFrame implements ActionListener{

    //private JTextArea texto;
    private JTextField leitor;
    private JButton botao;
    private JList<String> listinha1,listinha2;
    //Primeira parte - criando os widgets e definindo as posicoes no layout.
    public Suingue(){
        super("Leitor de arquivos 8000"); // Definindo o nome da janela
        setSize(512,512); // Setando o tamanho inicial da janela

        //texto = new JTextArea();
        leitor = new JTextField(25); //25 pra o campo de texto nao ficar pequenininho
        botao = new JButton("Listar");
        listinha1 = new JList<>();
        listinha2 = new JList<>();
        botao.addActionListener(this); // pode ter coisa dentro  //primeiro erro rapaziada
        //texto.setEditable(false);
        JPanel painel = new JPanel();
        painel.add(leitor);
        painel.add(botao);
        
        setLayout(new BorderLayout());
        add(painel,BorderLayout.SOUTH);
        add(listinha1,BorderLayout.WEST);
        add(listinha2,BorderLayout.EAST);
        //add(texto,BorderLayout.CENTER);

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
    //Segunda parte - tratamento de eventos.
    @Override
    public void actionPerformed(ActionEvent e){
        if(e.getSource() == botao){ // No caso de mais de um botao, seria necessario verificar de onde o evento eh oriundo.
            String nomeArq = leitor.getText();
            try{
                Scanner varredor = new Scanner(new File(nomeArq));
                String aux = "";
                while(varredor.hasNext()){
                    String linha = varredor.nextLine();
                    aux+= linha + "\n";
                }
                String [] listinhaStrings = aux.split("\\s+");
                listinha1.setListData(listinhaStrings);
                String [] listinhaCopia = listinhaStrings.clone();
                Arrays.sort(listinhaCopia);
                listinha2.setListData(listinhaCopia);
                //texto.setText(aux);
            }catch(FileNotFoundException ex){
                //texto.setText("erro ao abrir paizao");
                System.out.println("erro ao abrir paizao");
            }
        }
    }
    //Terceira parte - mostrando
    public static void main(String [] args){
        Suingue suingue = new Suingue();
        suingue.setVisible(true);
    }
}