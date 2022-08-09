/*287. Find the Duplicate Number
Medium

15584

1977

Add to List

Share
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
*/


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
       int i =0  , n= nums.size();
        
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
        for( i =0 ;i < n ; i++)
        {
            if(nums[i] != i+1)
                return  nums[i];
        }
        return 0;
        
    }
};
