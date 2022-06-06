class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        
         if (obstacleGrid.length<1)
            return 0;


        int m= obstacleGrid.length;
        int n = obstacleGrid[0].length;
        int[][] dp = new int[m+1][n+1];
        int ans =  help2(m,n,obstacleGrid, dp);

        return ans;
        
    }
    
    public static int  help2(int m,int n,int[][] grid,int[][] dp)
    {
        if (m==1 && n==1 && grid[m-1][n-1]!=1)
        {
            return 1;
        }
        if(m<1 || n<1)
            return 0;


        if (grid[m-1][n-1]==1)
            return 0;
        
        if (dp[m][n]!=0)
            return dp[m][n];

       dp[m][n] += help2(m-1,n,grid,dp);
       dp[m][n] += help2(m,n-1,grid,dp);

       return dp[m][n];

    }
}
