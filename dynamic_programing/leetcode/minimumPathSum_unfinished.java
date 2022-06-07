class Solution {
    
      
    public int minPathSum(int[][] grid) {
        
       if(grid.length<1)
            return 0;
        int m = grid.length;
        int n = grid[0].length;


        int[][] dp =new int[m+1][n+1];

        for(int[] a : dp)
            Arrays.fill(a,Integer.MAX_VALUE);
       int ans = help(m,n,0,grid,dp);

        return ans;

    }
    
     public static int help(int m ,int n ,int sum, int[][] grid, int[][] dp)
    {
        if(m==1 && n==1 )
        {
            dp[m][n] = Math.min( sum+grid[m-1][n-1], dp[m][n] );

            return dp[m][n];
        }

        if (m<1 || n<1)
        {
            return Integer.MAX_VALUE;
        }

        if (dp[m][n]!=Integer.MAX_VALUE)
            return dp[m][n];


       dp[m][n] = Math.min( help(m-1,n,sum+grid[m-1][n-1],grid,dp),help(m,n-1,sum+grid[m-1][n-1],grid,dp));


        return dp[m][n];
    }

}
