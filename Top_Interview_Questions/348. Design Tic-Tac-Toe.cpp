/*For a given n, initialize arrays rows and cols of size n with the value of every element set to 0.

For each move, we must increment/decrement the row, column, diagonal, and anti-diagonal according to who is the current player and which cell was marked. If the current player is player 1, we increment the value and if it is player 2, we decrement the value.

Note: If we apply simple math rules, we can increment or decrement the values irrespective of the player.

We can use an additional variable currentPlayer with the value 1 for player 1 and -1 for player 2, and add the value of currentPlayer to the current row, column, diagonal and anti-diagonal.

As a final step, we must determine whether the current player has won the game. If any row, column, diagonal, or anti-diagonal is equal to n (for player 1) or -n (for player 2) then the current player has won the game.*/

class TicTacToe {
public:

    vector<int> rows;
    vector<int> cols;
    int diagonal;
    int antidiagonal;
    int n;
    TicTacToe(int n) {

        rows = vector<int>(n,0);
        cols = vector<int>(n,0);
        antidiagonal = 0;
        diagonal = 0;
        this->n = n;

    }
    

    int move(int row, int col, int player) {

        int curr = (player == 1) ? 1 : -1;   //ad or substract based on player

        rows[row] += curr;               //update rows
        cols[col] += curr;                 //update cols

        if (row == col) diagonal += curr;  //update diagonal

        if (col == (n - row - 1)) antidiagonal += curr;  //update antidiagonal
        
        
        
        // if any player wins then any row or col must have abs value equal to n 
        if ( abs(rows[row]) == n || abs(cols[col]) == n || abs(diagonal) == n || abs(antidiagonal) == n)
            return player;

        return 0;

    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
