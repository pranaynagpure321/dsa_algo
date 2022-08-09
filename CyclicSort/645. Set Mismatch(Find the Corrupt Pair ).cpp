/*645. Set Mismatch
Easy

2134

588

Add to List

Share
You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.

 

Example 1:

Input: nums = [1,2,2,4]
Output: [2,3] */


class Solution {
    public int[] findErrorNums(int[] nums) {
        
        int i =0 , n = nums.length;
        while(i < n)
        {
            
            int correct = nums[i] -1;
            
            if(nums[i] != nums[correct])
            {
                nums[i] = nums[i] ^ nums[correct];
                nums[correct] = nums[i] ^ nums[correct];
                nums[i] =  nums[i] ^ nums[correct];
            }
            
            else i++;
        }
        
        int[] ans = new int[2];
        
        for( i =0 ;i<n ;i++)
        {
            if(nums[i] != i+1)
            {
                ans[0] = nums[i];
                ans[1] = i+1;
            }
        }
        
        return ans;
    }
    
}
