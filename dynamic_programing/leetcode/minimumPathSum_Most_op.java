class Solution {
    
    public int minPathSum(int[][] grid) {
        
       if(grid.length<1)
            return 0;
        int m = grid.length;
        int n = grid[0].length;


        int[][] dp =new int[m+1][n+1];

        for(int[] a : dp)
            Arrays.fill(a,-1);
       int ans = help(m,n,grid,dp);

        return ans;

    }
    
     public static int help(int m ,int n , int[][] grid, int[][] dp)
    {
         if(m==1 && n==1 )
        {
            return grid[0][0];
        }

        if (m<1 || n<1)
        {
            return -1;
        }

        if (dp[m][n]!=-1)
            return dp[m][n];

        int up = help(m-1,n,grid,dp);
        int left=help(m,n-1,grid,dp);

        if(up==-1)
        {
            return left+grid[m-1][n-1];
        }
        if(left==-1)
        {
            return up+grid[m-1][n-1];
        }

        return dp[m][n]=Math.min(up,left)+grid[m-1][n-1];
    }

}
