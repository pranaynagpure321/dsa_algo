class Solution {
public:
    int mx =0;
    vector<vector<int>> dp;
    int dfs(vector<vector<char>>& matrix , int  row , int col)
    {
       if( row>= matrix.size() || col >= matrix[0].size())
       return 0;

       if(dp[row][col] !=-1) return dp[row][col];
       int right = dfs(matrix, row, col+1);
       int diagonal = dfs(matrix,row+1, col +1 );
       int down = dfs(matrix, row+1, col);
        int ans  = 0;
       if(matrix[row][col] == '1')
       {
           ans = 1+min(right, min(diagonal,down));  // trick to solve the question 1+ min(right , diagonal, down)
           mx = max(mx, ans);
       }
       else dp[row][col]= 0;

       return dp[row][col] =ans;
    }

    int tabulation(vector<vector<char>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp (m+1, vector<int>(n+1,0));

        int mx =0;
        for(int i = m-1 ; i>=0 ; --i)
        {
            for(int j = n-1 ; j>= 0 ; --j)
            {
                int right = dp[i][j+1];
                int diagonal = dp[i+1][j+1];
                int bottom = dp[i+1][j];

                if(matrix[i][j] == '1')
                {
                    dp[i][j] = 1 + min(right, min(diagonal,bottom));

                    mx = max(mx, dp[i][j]);
                }      

            }
        }
        //time O(mn)
        //space O(mn)
        return mx*mx;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        

        // below is recusion and tabulatio appraoch
    //    int m = matrix.size(), n = matrix[0].size();
    //    dp= vector<vector<int>>(m, vector<int>(n,-1));
    //    dfs(matrix,0,0);

        return tabulation(matrix);
    }
};
