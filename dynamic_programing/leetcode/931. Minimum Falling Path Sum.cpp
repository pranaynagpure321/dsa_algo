class Solution {
public:
    vector<vector<int>> dp;
    int dfs(vector<vector<int>>& matrix , int i ,int j)
    {   
        if(  j<0 ||   j>= matrix.size() ) return INT_MAX;

        if(i == (matrix.size()-1)) return matrix[i][j];

        if(dp[i][j]!= -1) return dp[i][j];

        
        int left =   dfs(matrix, i+1,j-1 );
        int center = dfs(matrix,i+1,j);
        int right =   dfs(matrix, i+1,j+1 );
 
       return dp[i][j] = min(left,min(right,center)) + matrix[i][j];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n= matrix[0].size();

        if(n == 1) return matrix[0][0];
        dp.resize(m,vector<int>(n,-1));
        int res =INT_MAX;
        
        for(int j = 0 ;j< n ;j++)
        {
            res = min(res, dfs(matrix, 0,j ));
        }
        return res;
    }
};

//time O(n2)


// bottam up java
class Solution {
    public int minFallingPathSum(int[][] matrix) {
        int n  = matrix.length;
        int[][] dp = new int[n+1][n+1];

        for(int  i = n-1 ; i>=0 ;i--)
        {
            for(int j =0 ;j <n ; j++)
            {
                if(j ==0 )
                {
                    dp[i][j] = Math.min(dp[i+1][j], dp[i+1][j+1]) + matrix[i][j];
                }
               else if(j == n-1)
                {
                    dp[i][j] = Math.min(dp[i+1][j], dp[i+1][j-1]) + matrix[i][j];
                }
                else
                {
                    dp[i][j] = Math.min(dp[i+1][j+1],Math.min(dp[i+1][j], dp[i+1][j-1])) + matrix[i][j];
                }

            }
        }

        int res = Integer.MAX_VALUE;

        for(int j =0 ;j<n ;j++)
        res = Math.min(dp[0][j],res);


        return res;


    }
}
