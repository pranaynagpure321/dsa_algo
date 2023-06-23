class Solution {
public:
    int dp[1001][3][101];
    int dfs(vector<int>& prices, int k , int idx, int buy)
    {
        if(idx>= prices.size() || k==0 ) return 0;

        int profit = 0;

        if(dp[idx][buy][k] != -1 ) return dp[idx][buy][k];
        if(buy == 0)
        {
            profit = max(dfs(prices, k,idx+1, buy), -prices[idx] + dfs(prices,k,idx+1,1));
        }

        if(buy == 1)
        {
            profit = max(dfs(prices, k , idx+1, buy), prices[idx] + dfs(prices,k-1,idx+1, 0));
        }

        return dp[idx][buy][k]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp, -1, sizeof dp);
        return dfs(prices,k, 0, 0);
    }

    //time O(Nk)
    // space O(nk)
};
