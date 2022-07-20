class Solution {
    
    
    public static int mod = 1000000007;
    public static int  help(int n , int maxValue ,  int starting,int[][] dp)
    {
        if(n == 0 )
        {
            return 1;
        }
        int ans =0;
        if(dp[starting][n] != 0)
            return dp[starting][n];

        for(int i = starting ;i <= maxValue ; i++) {
            if (i % starting == 0)
                ans += help(n - 1, maxValue, i, dp);

            if (ans > mod) ans = ans % mod;

            dp[starting][n] += ans;
        }

        return  dp[starting][n]= ans%mod;
    }
    public int idealArrays(int n, int maxValue) {
        
        int[][] dp = new int[maxValue+1][n+1];
        int ans = help(n,maxValue,1,dp);

        return  ans;
    }
}
