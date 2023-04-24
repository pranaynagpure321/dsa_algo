class Solution {
public:
    int mod = 1e9 + 7;
    int dp[100001];
    int dfs(string &s , int k, int idx)
    {
        if(idx== s.size()) return 1;

        if(dp[idx] !=-1) return dp[idx];
        long ways = 0 ;  
        long sum =0;

        for(int i =idx ;i< s.size(); i++)
        {
           sum = sum*10 + (s[i]-'0');
           if(sum >= 1 and sum <= k)
           ways  = (ways%mod + dfs(s,k,i+1)%mod)%mod;
           else 
           break;
        }

        return dp[idx]=ways ;
    }

    int numberOfArrays(string s, int k) {
        int n = s.size();
        memset(dp,-1,sizeof(dp));
        return dfs(s,k,0);
    }
};
