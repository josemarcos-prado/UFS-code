import java.util.Random;

public enum categoria {
    ASSISTENTE_ADMINISTRATIVO(0, 500.00, 1500.00),
    ENGENHEIRO_JUNIOR(1, 1000.00, 2500.00),
    ENGENHEIRO_PLENO(2, 2000.00, 4500.00),
    ENGENHEIRO_SENIOR(3, 4000.00, 7500.00);

    private final int ordem;
    private final double minSalario;
    private final double maxSalario;
    private static final Random random = new Random();

    categoria(int ordem, double minSalario, double maxSalario) {
        this.ordem = ordem;
        this.minSalario = minSalario;
        this.maxSalario = maxSalario;
    }

    public int getOrdem() {
        return ordem;
    }

    public double gerarSalarioAleatorio() {
        return minSalario + (maxSalario - minSalario) * random.nextDouble();
    }

    public String getNomeFormatado() {
        String[] partes = this.name().toLowerCase().split("_");
        StringBuilder nomeFormatado = new StringBuilder();
        for (String parte : partes) {
            nomeFormatado.append(Character.toUpperCase(parte.charAt(0))).append(parte.substring(1)).append(" ");
        }
        return nomeFormatado.toString().trim();
    }
}