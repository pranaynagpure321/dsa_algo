class Solution {
    
     public static int dfs(int s ,int e ,int k ,int[][] dp )
    {
        if(k ==0 && s==e ) { return 1 ;}

        if(k == 0 || e-s > k  ) return 0;

        if(dp[1000+s][k] != -1)
            return dp[1000+s][k];

      long a =  dfs(s-1, e,k-1, dp);
       a += dfs(s+1,e,k-1,dp);

       dp[1000+s][k] = (int)a%1000000007;

       return  dp[s+1000][k];
    }
    public int numberOfWays(int startPos, int endPos, int k) {
        
        
        if((endPos- startPos - k)%2 !=0) return 0;
        
          int[][] dp = new int[4001][1001];

        for(int[] a : dp)
            Arrays.fill(a,-1);

       int ans = dfs(startPos,endPos,k,dp)%1000000007;

        return ans;
        
    }
}
