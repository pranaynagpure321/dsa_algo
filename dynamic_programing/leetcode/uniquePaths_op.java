class Solution {
    
    
    public int uniquePaths(int m, int n) {
        
        if (m==0 || n==0)
        {
            return 0;
        }

        int[][] dp = new int[m+1][n+1];


        int ans = help(m,n,dp);

        return ans;
        
    }
    
    
     public static int help(int m,int n,int [][] dp)
    {
        if (m==1 && n==1)
        {
            return 1;
        }
        if (m<1 || n<1)
            return 0;

        if (dp[m][n]!=0)
            return dp[m][n];

        dp[m][n] += help(m-1,n,dp);
        dp[m][n] += help(m,n-1,dp);

        return dp[m][n];
    }
