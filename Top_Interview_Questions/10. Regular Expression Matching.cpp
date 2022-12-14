class Solution {
public:
    vector<vector<int>> dp;
    bool dfs(string s, string p, int i, int j)
    {
        if(i>= s.size() && j>= p.size()) return true;

        if(j>= p.size()) return false;

        if(dp[i][j]!=-1) return dp[i][j];

        bool match = i<s.size() &&  (s[i] ==p[j] || p[j]=='.');

        if(j+1 < p.size() && p[j+1]=='*')
        {
          return dp[i][j]= ( dfs(s,p,i,j+2) or (match && dfs(s,p,i+1,j)) );    // either dont take * char or take * char
        }

        if(match)          // if both chars match then increment both counters
        return dp[i][j]=  dfs(s,p,i+1,j+1);

        return false;
    }


    bool isMatch(string s, string p) {

        dp= vector<vector<int>>(s.length()+1, vector<int>(p.size(),-1));
      
        //time O(m*n)
        
        return dfs(s,p,0,0);
    }
};
