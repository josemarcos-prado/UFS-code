import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Random;

public class GeradorBaseDeDados {

    private static final Random random = new Random();

    public static void main(String[] args) {
        List<funcionario> funcionarios = new ArrayList<>();
        int numeroDeFuncionarios = 20;

        for (int i = 0; i < numeroDeFuncionarios; i++) {
            int tipoFuncionario = random.nextInt(4);
            switch (tipoFuncionario) {
                case 0 -> funcionarios.add(new AssistenteAdministrativo());
                case 1 -> funcionarios.add(new Engenheiro(categoria.ENGENHEIRO_JUNIOR));
                case 2 -> funcionarios.add(new Engenheiro(categoria.ENGENHEIRO_PLENO));
                case 3 -> funcionarios.add(new Engenheiro(categoria.ENGENHEIRO_SENIOR));
            }
        }
        funcionario[] funcionariosArray = funcionarios.toArray(new funcionario[0]);

        Arrays.sort(funcionariosArray);

        for(funcionario f : funcionariosArray){
            System.out.println(f);
        }
    }
}