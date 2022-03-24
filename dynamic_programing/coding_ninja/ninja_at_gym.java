import java.util.ArrayList;

public class Solution {
    static int max=0;
    int[] dp;
    public static void dfs(ArrayList<Integer> rack,int n,int start,int previous,int sum)
    {
         if(sum>max)
            max=sum;
        if(dp[start]!=0)
            return ;
        for(int i = start+1 ;i < n ;i++)
        {
            if(previous<rack.get(i)){
                sum +=rack.get(i);
                dfs(rack,n,i,rack.get(i),sum);
                sum -=rack.get(i);
            }
        }
            
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
        
        return max;
        
    }
}
