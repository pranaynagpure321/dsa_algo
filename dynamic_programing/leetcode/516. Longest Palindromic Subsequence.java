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
