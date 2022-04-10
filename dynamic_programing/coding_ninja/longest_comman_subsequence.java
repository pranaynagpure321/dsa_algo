
public class Solution {
	
	 static int [][] dp;

	public static int help(int i,int j,String s, String t) {

        if (i>=s.length() || j>=t.length())
            return 0;

        if(dp[i][j]!=-1)
            return dp[i][j];

        else if (s.charAt(i)==t.charAt(j)) {
            dp[i][j] = 1 + help(i + 1, j + 1, s, t);
            return dp[i][j];
        }

        else
            dp[i][j] = Math.max(help(i+1,j,s,t),help(i,j+1,s,t));
        return dp[i][j];

    }
	public static int lcs(String s, String t) {
		//Your code goes here
		dp= new int[s.length()][t.length()];

        for(int i=0;i<s.length();i++)
		 for(int j =0 ;j<t.length();j++)
          dp[i][j]=-1;
		
		
        return help(0,0,s,t);
    }

}
