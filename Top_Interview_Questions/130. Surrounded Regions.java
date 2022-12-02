class Solution {


   
    void dfs(char[][] board,int i ,int j,  boolean[][] vis)
    {
        if(i <0 || j<0 || i>= board.length || j>= board[0].length ||  vis[i][j]==true  || board[i][j] != 'O') return;

        vis[i][j] = true;
        board[i][j] = 'P';
        dfs(board, i+1,j ,vis);
        dfs(board, i-1,j ,vis);
        dfs(board, i,j+1 ,vis);
        dfs(board, i,j-1 ,vis);
    }
    public void solve(char[][] board) {
        
        boolean[][] vis = new boolean[board.length][board[0].length];
        int  m = board.length , n = board[0].length;

        //convert all O => p if they are attached with boarder O 
        for(int i =0 ;i< m ;i++)
        {   
            for(int j =0 ; j< n;j++)
            {
                if(i ==0 || j ==0 || i== m-1 || j == n-1)
                if(!vis[i][j] && board[i][j]!='X')
                 dfs(board, i,j ,vis);
            }
        }
        //convert remaining O=> X
         for(int i =0 ;i< m ;i++)
        {   
            for(int j =0 ; j< n;j++)
            {
                if(board[i][j] == 'O')
                board[i][j] ='X';
            }
        }
        //convert all the P => O
         for(int i =0 ;i< m ;i++)
        {   
            for(int j =0 ; j< n;j++)
            {
                if(board[i][j] == 'P')
                board[i][j] ='O';
            }
        }

    }
}
