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


//tabulation
class Solution {
    public boolean isMatch(String s, String p) {

        //if(s.length() == 0 )return true;
        int  m = p.length() ,n = s.length() ; // j, i ;    
        boolean[][] dp = new boolean[m+1][n+1]; 
       
         for(int i=p.length()-1;i>=0;i--){      // to handle *, **, *** like patterns starting
            if(p.charAt(i)!='*')
                break;
            else
                dp[i][s.length()]=true;
        }

        dp[m][n] = true;

        for(int i = m-1; i>=0 ;i--)
        {
            for(int j = n-1 ;j>= 0 ;j--)
            {
                if(p.charAt(i) == '?' || p.charAt(i) == s.charAt(j))
                {
                    dp[i][j] = dp[i+1][j+1];
                }
                else if(p.charAt(i) == '*')
                {
                    dp[i][j] =  dp[i+1][j] || dp[i][j+1];
                }
                else{
                    dp[i][j] = false;
                }
            }
        }

        return dp[0][0];
    }
}

/*"abcabczzzde"
p =
"*abc???de*"*/
