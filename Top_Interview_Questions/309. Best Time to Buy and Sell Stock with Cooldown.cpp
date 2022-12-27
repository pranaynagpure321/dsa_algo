class Solution {

    int[][] dp;
    int dfs(int[] prices, int idx, int buy)
    {
        if(idx >= prices.length )
        return 0;

        if(dp[idx][buy] != -1) return dp[idx][buy];

        if(buy == 0)
        return dp[idx][buy]= Math.max( -prices[idx] + dfs(prices,idx+1,1) , dfs(prices, idx+1, 0) );
        return dp[idx][buy] = Math.max(prices[idx] + dfs(prices, idx+2,0), dfs(prices, idx+1,1));
    }
    public int maxProfit(int[] prices) {
        dp = new int[prices.length][2];

        for(var a : dp)
        {
            Arrays.fill(a,-1);
        }
        return dfs(prices, 0, 0);
      
      //time O(N)
    }
}
