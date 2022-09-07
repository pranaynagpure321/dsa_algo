class Solution {
    public int help(int n , int[] dp)
    {
        if(n==0 ) return 1;
        if(n <0 ) return 0;
        
        if(dp[n]!= -1) return  dp[n];
        int steps =   help(n-1, dp);
        steps +=   help(n-2,dp);
            
        return dp[n]= steps;
    }
    public int climbStairs(int n) {
        
        int[] dp = new int[n+1];
        
        Arrays.fill(dp,-1);
        
        int ans  = help(n,dp);
        
        //time O(N)
        //space O(N)
        
        return ans;
        
    }
}
