class Solution {
public:
    int min_sum = INT_MAX;
    int dp[501][501];
    int help(string &s , int i , int j, int sum )
    {
        if(i>= j)
        {   
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        int res =INT_MAX ;
        if(s[i] == s[j])
        {
           res =  help(s, i+1, j-1, sum);
        }
        return dp[i][j] =  min( res , 1+ min( help(s,i+1,j, sum+1),help(s,i,j-1, sum+1)));
    }

    int minInsertions(string s) {
        int n = s.size()-1;
        memset(dp,-1, sizeof(dp));
        int res =  help(s,0,n,0);
        return res;
    }
};
