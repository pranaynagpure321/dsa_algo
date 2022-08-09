/*Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

 

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]
Example 2:

Input: nums = [1,1]
Output: [2] */


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        int n = nums.size();
        
       vector<int> ans;
       int i =0 ;
        
        while(i  < n )
        {
            int correct = nums[i] -1;
            
            if(nums[i] != nums[correct])
            {
                int temp = nums[correct];
                nums[correct] = nums[i];
                nums[i] = temp;
            }
            
            else i++;
        }
        
        
        for( i  =0 ;i< n ;i++)
        {
            if(nums[i] != i+1)
                ans.push_back(i+1);
        }
        
        return ans;
    }
};
