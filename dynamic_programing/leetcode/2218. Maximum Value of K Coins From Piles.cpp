class Solution {
public:

    int maxProfit(vector<vector<int>> &piles , int i , int k,vector<vector<int>>& dp)
    {
        if(k == 0 || i== piles.size() ) return 0;

        if(dp[i][k] !=-1) return dp[i][k];
        //take  
        int res = maxProfit(piles, i+1, k,dp);

        //not take
        int cur =0, size = piles[i].size();
        for(int j =0 ;j< min(k, size) ;j++)
        {
            cur += piles[i][j];
            res=  max(res, cur + maxProfit(piles, i+1,k-j-1,dp));
        }

        return  dp[i][k]=res;
    }

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {

        int n = piles.size();
        vector<vector<int>> dp(n+1, vector<int>(k+1,-1));
        return maxProfit(piles, 0,k,dp);

    }
};
