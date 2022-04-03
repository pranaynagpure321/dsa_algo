public class Solution {
    
    public static int help(int arr[],int root,int cureent,int[] dp)
    {
        if(dp[root]!= 0)
            return dp[root];
       for (int i =root;i<arr.length;i++)
       {
           if(arr[i]>cureent) {
               dp[root] = Math.max(dp[root],help(arr, i, arr[i], dp)+1);
           }
       }

       if(dp[root]==0)
           dp[root]=1;

       return dp[root];
    }

	public static int longestIncreasingSubsequence(int arr[]) {
		//Your code goes here
        
        if(arr.length==0)
        return 0;
        if(arr.length==1)
            return 1;
        int[] dp =new int[arr.length];
        help(arr,0,-100001,dp);
       
       int max=0;
       for (int a : dp)
           if(a>max)
               max=a;
       // System.out.println(max);
        
        return Math.max(max-1,1);

    }
    

}
