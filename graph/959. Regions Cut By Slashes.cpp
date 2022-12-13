class Solution {
public:

    void dfs(int row , int col, vector<vector<int>> &matrix)
    {
        if(row <0 || col<0 || row>=matrix.size() || col>= matrix[0].size() || matrix[row][col]==1) return;

        matrix[row][col] =1;

        dfs(row+1,col,matrix);
        dfs(row-1,col,matrix);
        dfs(row,col+1,matrix);
        dfs(row,col-1,matrix);
    }

    int regionsBySlashes(vector<string>& grid) {
    
        int n = grid.size();
       // cout<<"hello"<<endl;
        vector<vector<int>> matrix(3*n, vector<int>(3*n, 0));

        for(int row = 0 ; row <n ;row++)
        {         
            for(int col =0 ; col < n ; col++)
            {
                if(grid[row][col] =='/')
                {
                    matrix[row*3][col*3+2]= matrix[row*3+1][col*3+1]=matrix[row*3+2][col*3] =1;
                }
                else if(grid[row][col] =='\\')
                {
                    matrix[row*3][col*3]= matrix[row*3+1][col*3+1]=matrix[row*3+2][col*3+2] =1;
                }
            }
        }
       // cout<<"hello"<<endl;
        int res =0;
        for(int row = 0 ; row <3*n ;row++)
            for(int col =0 ;col<3*n ; col++)
              if(matrix[row][col]==0)
                {
                    dfs(row,col,matrix);
                    res++;
                }
            
         //time O(N2)
        return res;

    }
};
