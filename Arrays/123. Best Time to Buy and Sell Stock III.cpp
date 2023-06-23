class Solution {
public:

    vector<vector<vector<int>>> dp;
    int dfs(vector<int>& prices, int buy, int t, int idx)
    {
        if(idx >= prices.size() || t ==0 ) return 0;

        if(dp[idx][buy][t] != -1) return dp[idx][buy][t]; 
        int profit =0;

        if(buy == 0)
        {
            profit = max( dfs(prices,buy, t, idx+1), -prices[idx] + dfs(prices,1,t,idx+1) );
        }
        if(buy == 1)
        {
            profit = max( dfs(prices,buy,t,idx+1), prices[idx] + dfs(prices, 0, t-1, idx+1));
        }
        return dp[idx][buy][t]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(2,vector<int>(3,-1)));
        return dfs(prices, 0, 2,0);
    }
};
