class Solution {
public:
    vector<vector<int>> dp;
    bool isCharRemain(string p ,int j)
    {
        for(int k =j ;k<p.size() ;k++)
        if(p[k] != '*') return true;

        return false;
    }

    bool dfs(string & s, string &p, int i , int j )
    {
        if(i>= s.size() && j>= p.size()) return true;
        if(j>= p.size()) return false;
        if(i>= s.size()) 
        {
            if(isCharRemain(p,j)) return false;
            return true;
        }
       
        if(dp[i][j] !=-1) return dp[i][j];

        bool match =  (s[i] == p[j] || p[j] =='?');

        if(  p[j] == '*')
        {
           return dp[i][j] = ( dfs(s,p,i,j+1) ||  dfs(s,p,i+1,j)  || dfs(s,p,i+1,j+1) ) ;  //using * for single match 2 multiple match and no match(skip)
        }

        if(match)
        return  dp[i][j] = dfs(s,p,i+1,j+1);

        return false;

    }

    bool isMatch(string s, string p) {
        dp.resize(s.size(), vector<int>(p.size(),-1));
        return dfs(s,p,0,0);
    }
};
