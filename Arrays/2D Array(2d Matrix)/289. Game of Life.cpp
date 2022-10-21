class Solution {
public:
     int getLiveNeighbours(vector<vector<int>>& board,int row,int col)
    {
        int cnt = 0, i = max(0,row-1);
        
        for (; i <= row+1 and i<board.size(); ++i)
        {
            int j =  max(0,col-1);
            for (; j <= col + 1 and j < board[i].size(); ++j)
            {
                if (row == i and j == col ) continue;
                if ( abs(board[i][j]) ==1)
                    cnt++;
            }
 
        }
        return cnt;

    }
    void gameOfLife(vector<vector<int>>& board) {
         for (int i = 0; i < board.size(); ++i)
        {
             for (int j = 0; j < board[i].size(); ++j)
            {

                 // 1 => 0 means -1
                // 0 => 1 means 10
                int cnt = getLiveNeighbours(board, i, j);
                 //cout << " cell  i => " << i << " j=> " << j << " cnt=> " << cnt << endl;
                if (board[i][j] == 0 and  cnt == 3)
                {
                    board[i][j] = 10;   
                }
                else if  ( (board[i][j] == 1) and (cnt > 3 || cnt < 2) ) 
                {   
                    board[i][j] = -1;
                }
                 
            }


        }
        
        for(int i =0 ;i< board.size(); ++i){
            replace(board[i].begin(), board[i].end(), -1, 0);
            replace(board[i].begin(), board[i].end(), 10, 1);
        }
        
        //time O(m*n)
        //space O(1)
        
    }
};
