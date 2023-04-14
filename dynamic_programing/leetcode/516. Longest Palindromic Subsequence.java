class Solution {

    public int help(String s, int i, int j,int[][] memo){

        if(i == j)
        return 1;

        if(i>j) return 0;

        if(memo[i][j] != -1) return memo[i][j];

        int res =0;
        if(s.charAt(i) == s.charAt(j))
        res = Math.max(res,2+ help(s,i+1,j-1,memo));

        return memo[i][j] = Math.max(res, Math.max( help(s,i+1,j,memo) , help(s,i,j-1,memo)));
      
    }
    
    public int longestPalindromeSubseq(String s) {
        int[][] memo = new int[s.length()][s.length()];

        for(int[] a: memo)
        Arrays.fill(a, -1);

        return help(s,0,s.length()-1, memo);
    }
}



//tabulation using lcs 

class Solution {
public:

    int lcs(string s1 , string s2)
    {
        int n = s1.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));

        for(int i =1 ; i <= n ;i++)
        {
            for(int j = 1 ;j <= n ;j++)
            {
                if(s1[i-1] == s2 [j-1])
                dp[i][j] = dp[i-1][j-1] +1;
                else
                {
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }

        return dp[n][n];
    }
    int longestPalindromeSubseq(string s) {

        string s1 =s;
        reverse(s.begin(), s.end());

        return lcs(s1,s);
    }
};
