
public class Solution {
    
   

	public static int longestIncreasingSubsequence(int arr[]) {
		//Your code goes here
        
        if(arr.length==0)
        return 0;
        if(arr.length==1)
            return 1;
        int[] dp =new int[arr.length];
      
        int max=0;
        for(int i =0 ;i< dp.length;i++)
        {
            int tempmax=0;
            for(int j =0;j<i;j++){
                if(arr[j]<arr[i]){
                    if(dp[j]>tempmax)
                        tempmax = dp[j];       
                }
                
            }
            
            dp[i] = tempmax+1;
            
            if(dp[i]> max)
                max=dp[i];
        }
        
        return max;

    }
    

}
