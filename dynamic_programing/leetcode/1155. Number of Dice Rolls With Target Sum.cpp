class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        
        int mod = 1e9+7;
        
        //creating dp vector for next state // tip always look for states for next step in dp
        vector<vector<int>> dp(n+1, vector<int> (target+1,-1));
        int ans = help(n,k,target,mod,dp);
      
        return (ans)%mod;
    }
    
    int help(int n ,  int k ,int target,int mod, vector<vector<int>> &dp)
    {
        if(target == 0 && n==0 )
        {
            //cout<<s<<endl;
            return 1;
        }
        if(target < 0  || (n==0 && target>0) ) return 0;
        
        if(dp[n][target] != -1)
            return dp[n][target];
        
        int ans =0 ;
        for(int i = 1 ; i<= k   ; i++)
        {
            
             ans += help(n-1, k, target-i,mod,dp)%mod;
             ans = ans%mod;
            
        }
         dp[n][target] = ans;
        
        return dp[n][target];
    }
};
