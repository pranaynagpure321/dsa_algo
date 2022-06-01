class Solution {
    
    static int ans = Integer.MAX_VALUE;
    public int jump(int[] nums) {
        
       
        if(nums.length==1) return 0;
        
        if(nums.length==2) return 1;
        
         ans=Integer.MAX_VALUE;
        
         return help(nums,0);
        
    }
    
    
     public static int help(int[] arr,int index)
    {
        if (index == arr.length-1)
        {
            return 0;
        }

        for (int i = 1;i<=arr[index];i++)
        {
            if(index+i<arr.length && arr[index+i]!=0)
            ans = Math.min(ans,1+help(arr,index+i));
        }
         
         if(ans==Integer.MAX_VALUE)
            return 0;
        

        return ans;
    }

   
}
