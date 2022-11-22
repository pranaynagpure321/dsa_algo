class Solution {
public:
int n, m;
    bool dfs(vector<vector<char>>& board,vector<vector<bool>>&vis,  string& word, int idx , int row, int col)
    {
        if (idx+1  >= word.length()) return true;

        char ch = word[idx+1];
       // cout<<"row=> "<<row<<" col=> "<<col<<" current char => "<<board[row][col]<<" next=> " <<ch<<endl;
        vis[row][col] = true;
        //up
        if(row-1 >=0 and board[row-1][col] == ch and !vis[row-1][col] and dfs(board,vis, word, idx+1, row-1, col))
            return true;
        //down
        if (row + 1 <m and board[row + 1][col] == ch and !vis[row + 1][col] and dfs(board, vis, word, idx + 1, row + 1, col))
            return true;
        //left
        if (col - 1 >=0  and board[row ][col-1] == ch and !vis[row ][col-1] and dfs(board, vis, word, idx + 1, row  , col-1))
            return true;
        //right
        if (col + 1 < n and board[row ][col+1] == ch and !vis[row ][col+1] and dfs(board, vis, word, idx + 1, row  , col+1))
            return true;

        vis[row][col] = false;

        return false;

    }

    bool exist(vector<vector<char>>& board, string word) {
         m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                vector<vector<bool>> vis(m, vector<bool>(n, false));
                if (board[i][j] == word[0] and dfs(board, vis, word, 0, i, j))
                    return true;
            }
        }

        return false;
    }
};
