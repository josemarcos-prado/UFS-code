public abstract class funcionario implements Comparable<funcionario> {
    private final double salario;
    private final categoria categoria;

    public funcionario(categoria categoria) {
        this.categoria = categoria;
        this.salario = categoria.gerarSalarioAleatorio();
    }

    public double getSalario() {
        return salario;
    }

    public categoria getcategoria() {
        return categoria;
    }

    //explicação da alterção do compareTo
    @Override
    public int compareTo(funcionario outro) {
        //usando como criterio a categoria
        //se a ordem das categorias é diferente, a decisão já está definida pela ordem do enum
        if (this.getcategoria().getOrdem() != outro.getcategoria().getOrdem()) {
            return Integer.compare(this.getcategoria().getOrdem(), outro.getcategoria().getOrdem());
        }
        //criterio de garantia, o salário
        //já que "this" e "outro" sao da msm categoria, ordena o salario de forma crescente
        return Double.compare(this.getSalario(), outro.getSalario());
    }

    @Override
    public String toString() {
        return String.format("Categoria: %s, Salário: R$ %.2f",
                getcategoria().getNomeFormatado(), salario);
    }
}