class Solution {
public:
    int dp[1001][1001];
    int dfs(string &t1, string &t2, int i, int j)
    {
        if(i>= t1.size() || j>=t2.size()) return 0;

        if(dp[i][j] !=-1) return dp[i][j];
        
        auto found = t1.find(t2[j], i);
        int pick =0;
        if(found != string::npos)
        {
            pick = 1+ dfs(t1,t2,found+1, j+1);
        }

        return dp[i][j]= max(pick,dfs(t1,t2,i,j+1));
    }

    int longestCommonSubsequence(string text1, string text2) {

        if(text1 == text2) return text1.size();
        memset(dp, -1, sizeof dp);
        
        //time O(m*n)
        return dfs(text1,text2,0,0);
    }
};
