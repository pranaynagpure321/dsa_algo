/*
55. Jump Game
Medium
 
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index. */



class Solution {
    
    static int ans = Integer.MAX_VALUE;
    public int jump(int[] nums) {
        
       
        if(nums.length==1) return 0;
        
        if(nums.length==2) return 1;
        
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
