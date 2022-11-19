class Solution {
public:
int sum =INT_MAX;

    int dfs(vector<int>& coins, int amt,int idx,vector<vector<int>>& dp)
    {
        if(amt == 0 ){  /*sum = min(sum,total);*/   return 0;}

        if(amt<0 || idx <0  ) return -1 ;

        if(dp[idx][amt]!= -1) return dp[idx][amt];

        int nottake = dfs(coins,amt,idx-1,dp);
        
       
        int take = INT_MAX;

        if(amt>= coins[idx])
        {
            int tmp = dfs(coins,amt- coins[idx],idx,dp);
            take =  (tmp == INT_MAX) ? INT_MAX  : tmp+1 ;
        }

       if(nottake == -1) return take;
 
        return dp[idx][amt] = min(take,nottake);
    }

    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        vector<vector<int>> dp (coins.size(), vector<int>(amount+1, -1));
       sum =  dfs(coins,amount,coins.size()-1,dp);
        return (sum==INT_MAX ) ? -1 : sum;
    }
};
