class Solution {
public:
    
    bool isSquare(int n)
    {
        int a = (int)sqrt(n);
        return a*a==n;
    }
    
    
    int dfs(int n , vector<int>& dp)
    {
       if(n ==0 )
           return 0;
        
        if(dp[n] !=INT_MAX)
            return dp[n];
        
        int ans =INT_MAX; 
        
        
        for(int i = sqrt(n) ;i>=1 ;i--)
        {
            ans  = min(ans , 1+dfs(n-(i*i), dp));
        }
        dp[n] = min(ans,dp[n]);
        
        return dp[n];
    }
    int numSquares(int n) {
        
        if(isSquare(n))
            return 1;
        
        vector<int> dp(n+1,INT_MAX);
        
       return dfs(n,dp); 
    }
};
