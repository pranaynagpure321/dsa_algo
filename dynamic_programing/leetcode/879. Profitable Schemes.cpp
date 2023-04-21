class Solution {
    public:
   // int ways =0;
    int dp[102][102][102];
   int mod =1e9 + 7;
    int totalSchemes(vector<int>& group, vector<int>& profit,int n , int minProfit , int idx)
    {
        if( n<0 ) return 0 ;
        if(idx>= group.size() )
        {
            if(minProfit >0 ) return 0;
            return 1;
        }
        if(minProfit<0 ) minProfit = 0;
        if(dp[idx][n][minProfit] != -1) return dp[idx][n][minProfit];

        //take
       int ways = totalSchemes(group, profit, n-group[idx], minProfit-profit[idx], idx+1) %mod;

        //nottake
      ways = (ways%mod  + totalSchemes(group, profit, n, minProfit, idx+1)%mod)%mod ;
        return dp[idx][n][minProfit] = ways;
    }

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
      
        memset(dp,-1, sizeof(dp));
        return totalSchemes(group, profit,  n,  minProfit, 0);
    }
};
