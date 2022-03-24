import java.util.ArrayList;

public class Solution {
    static int max=0;
    static int[] dp;
    public static int  dfs(ArrayList<Integer> rack,int n,int start,int previous,int sum)
    {
        
        if(dp[start] != 0)
            return dp[start];
        
        for(int i = start+1 ;i < n ;i++)
        {
            if(previous<rack.get(i)){
             
              int a =  dfs(rack,n,i,rack.get(i),sum);
                if(a>dp[start])
                    dp[start]=a;
               
            }
        }
        
        dp[start] +=rack.get(start);
        return dp[start] ;
    }
    public static int maxIncreasingDumbbellsSum(ArrayList<Integer> rack, int n) {
        // Write your code here.
        max=0;
        if(rack.size()==1)
            return rack.get(0);
        
        dp = new int[n];
        for(int i =0 ;i< n ;i++){
         
           dfs(rack,n, i,rack.get(i),rack.get(i));
        }
        
        for(int a: dp)
        {
            if(a>max)
                max=a;
        }
        
        return max;
        
    }
}
