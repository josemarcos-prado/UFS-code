public class Tabuleiro {
    private char [][] grid;

    public Tabuleiro () {
        grid = new char[3][3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++){
                grid[i][j] = ' ';
            }
        }
    }

    public String viraString () {
        String aux = "";
        for(int lin = 0; lin < 3; lin++) {
            for (int col = 0; col < 2; col++) 
                aux += grid[lin][col] + "|";
            aux += grid[lin][2] + "\n";
            if (lin != 2)
                aux += "-+-+-\n";
        }
        return aux;
    }

    public boolean  jogar (int lin, int col, char simbolo) {
        if (lin < 0 || lin > 2) return false;
        if (col < 0 || col > 2) return false;
        if (grid[lin][col] == ' '){
            grid[lin][col] = simbolo;
            return true;
        } else return false;
    }

    private boolean existeVencedor () {
        boolean aux = false;

        for (int lin = 0; lin < 3; lin++) {
            if (grid[lin][0] == grid[lin][1] && 
                grid[lin][1] == grid[lin][2] &&
                grid[lin][0] != ' ')
                aux = true;
        }
        
        for (int col = 0; col < 3; col++) {
            if (grid[0][col] == grid[1][col] && 
                grid[1][col] == grid[2][col] &&
                grid[0][col] != ' ')
                aux = true;
        }

        if (grid[0][0] == grid[1][1] && 
            grid[1][1] == grid[2][2] && 
            grid[0][0] != ' ')
            aux = true;

        if (grid[0][2] == grid[1][1] && 
            grid[1][1] == grid[2][0] && 
            grid[0][2] != ' ')
            aux = true;

        return aux;
    }

    public boolean empate () {
        boolean temVazio = false;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (grid[i][j] == ' ') 
                    temVazio = true;
            }
        }
        return (!temVazio && !existeVencedor());
    }

    public boolean acabou() {
        return (empate() || existeVencedor());
    }

}
