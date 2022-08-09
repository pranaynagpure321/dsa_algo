/*41. First Missing Positive
Hard

10951

1416

Add to List

Share
Given an unsorted integer array nums, return the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses constant extra space.

 

Example 1:

Input: nums = [1,2,0]
Output: 3*/

class Solution {
    public int firstMissingPositive(int[] nums) {
        
        int i =0 , n = nums.length;
        
        
        while(i < n )
        {
            int correct = nums[i] -1;
            
            if( nums[i] > 0 && correct < n  &&  nums[i] != nums[correct]  )
            {
                int temp = nums[i];
                nums[i] = nums[correct];
                nums[correct] = temp;
            }
            
            else i++;
        }
        
        for( i =0 ; i< n ;i++)
        {
            if(  nums[i] != i+1)
                return i+1;
        }
        return n+1;
        
    }
}
