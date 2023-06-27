class Solution {
public:

    vector<vector<int>> dp;
    bool dfs(string s1, string s2, string s3, int i, int j , int k)
    {
        
        if(i == s1.size() )
        return s2.substr(j) == s3.substr(k);

        if(j == s2.size() )
        return s1.substr(i) == s3.substr(k);
        
        if(dp[i][j] != -1) return dp[i][j]==1? true : false;
        bool ans =false;
        if(s1[i] == s3[k])
        {
            ans = dfs(s1,s2,s3,i+1,j,k+1); 
            if(ans) return true;
        }

        if(s2[j] == s3[k] and !ans)
        {   
            ans = dfs(s1,s2,s3,i,j+1,k+1);
            if(ans) return true;
        }
        dp[i][j] = ans == true ? 1 : 0;
        return   ans;

    }

    bool isInterleave(string s1, string s2, string s3) {
         if(s1.size() + s2.size()  != s3.size()) return false;
         int m= s1.size(), n = s2.size();
        dp = vector<vector<int>>(m, vector<int>(n,-1));

        return dfs(s1,s2,s3,0,0,0);
    }
};
