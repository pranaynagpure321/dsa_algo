class Solution {
    
     static int  mod = 1000_000_007, K;
    static int dfs(int row, int col, int sum ,  int[][] grid , int[][][] dp )
    {
        if(row>grid.length || col > grid[0].length)
            return 0;

        if(row == grid.length && col == grid[0].length)
        {
            sum += grid[row-1][col-1];
            if(sum%K ==0) {

                //System.out.println( s+",["+row+","+col+"]"+ "sum=> "+sum);
                return 1;

            }
            return 0;
        }

        if(dp[row][col][sum] != -1)
            return dp[row][col][sum];

        int ans  =0;
        ans  += dfs(row+1, col, (sum+grid[row-1][col-1])%K  , grid,dp  )%mod;
        ans += dfs(row, col+1, (sum+grid[row-1][col-1])%K,grid,dp)%mod;

        dp[row][col][sum] = ans%mod;

        return dp[row][col][sum] ;
    }
    public int numberOfPaths(int[][] grid, int k) {
        int dp[][][] = new int[grid.length+1][grid[0].length+1][k+1] ;
        K=k;
        for ( var a: dp) {
            for (var arr: a) {
                Arrays.fill(arr,-1);
            }

        }
        return dfs(1,1,0, grid ,dp )%mod;
    }
}
