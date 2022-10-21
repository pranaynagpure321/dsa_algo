to get neighbour of cell in matrix

```c++
this function check if your neighbours are one 
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
```    
