class Solution {
public:
     int dp[501][501];
    int dfs(int s, int e, vector<int>& v)
    {
        
        if(s>e) return 0;
        
        if(dp[s][e]!= -1) return dp[s][e];
        
        int Rsum=0;
        
        for(int i =s;i<=e;i++)
        {
            Rsum +=v[i];
        }
        int  Lsum=0;
        int ans =0;
        for(int i = s;i<e;i++)
        {
            Rsum -=v[i];
            Lsum += v[i];
            
            if(Lsum<Rsum) ans = max(ans,Lsum+dfs(s,i,v));
            if(Lsum == Rsum) ans = max(ans, Lsum+max(dfs(s,i,v), dfs(i+1,e,v)));
            
            if(Rsum < Lsum) ans = max(ans, Rsum+dfs(i+1,e,v));
            
            
        }
        dp[s][e]=ans;
        return dp[s][e];
    }
    
    int stoneGameV(vector<int>& stoneValue) {
        
        memset(dp, -1, sizeof dp);
        
       return dfs(0,stoneValue.size()-1,stoneValue);
        
        
    }
};
