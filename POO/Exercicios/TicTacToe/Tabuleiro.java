public class Tabuleiro {
    private char [][] peca;
    
    public Tabuleiro () {
        peca = new char [3][3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                peca[i][j] = ' ';
            }
        }
    }

    public boolean inserirPeca (int lin, int col, char simbolo) {
        if (lin < 0 || lin > 2) return false;
        if (col < 0 || col > 2) return false;
        if (peca[lin][col] == ' ') {
            peca[lin][col] = simbolo;
            return true;
        } else {
            return false;
        }
    }
}