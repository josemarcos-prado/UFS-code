class SaldoInsuficienteException extends Exception { }

public class ContaCorrente {
    private double saldo;

    public final double getSaldo() {
        return saldo;
    }

    public final void setSaldo(double saldo) {
        this.saldo = saldo;
    }

    public ContaCorrente (double saldo) {
        setSaldo(saldo);
    }

    public void retirar (double valor) throws SaldoInsuficienteException{    
        if (saldo < valor)      
            throw new SaldoInsuficienteException ();
        else
            setSaldo(saldo - valor);
    }

    public static void main(String[] args) {
        ContaCorrente cc = new ContaCorrente(1000);
        try {
        cc.retirar(100);
        System.out.println ("Saldo: " + cc.getSaldo());
        } 
        catch (SaldoInsuficienteException e) {
            System.out.println ("Saldo insuficiente");
        }
    }
}