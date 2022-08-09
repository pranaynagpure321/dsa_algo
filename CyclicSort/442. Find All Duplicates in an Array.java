/*442. Find All Duplicates in an Array
Medium

6910

269

Add to List

Share
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant extra space.

 

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]
Example 2:

Input: nums = [1,1,2]
Output: [1] */

class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        
        int i = 0 , n = nums.length;
        
        while(i < n)
        {
            int correct = nums[i]-1;
            
            if(nums[i] != nums[correct])
            {
                int temp = nums[i];
                nums[i] = nums[correct];
                nums[correct] = temp;
            }
            
            else i++;
        }
        
        var ans = new ArrayList<Integer>();
        
        for(i =0 ;i< n ;i++ )
        {
            if(nums[i] != i+1)
                ans.add(nums[i]);
        }
        
        return ans;
    }
}
