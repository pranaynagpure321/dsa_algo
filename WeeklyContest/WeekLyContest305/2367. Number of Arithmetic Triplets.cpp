/*You are given a 0-indexed, strictly increasing integer array nums and a positive integer diff. A triplet (i, j, k) is an arithmetic triplet if the following conditions are met:

i < j < k,
nums[j] - nums[i] == diff, and
nums[k] - nums[j] == diff.
Return the number of unique arithmetic triplets.

 

Example 1:

Input: nums = [0,1,4,6,7,10], diff = 3
Output: 2
Explanation:
(1, 2, 4) is an arithmetic triplet because both 7 - 4 == 3 and 4 - 1 == 3.
(2, 4, 5) is an arithmetic triplet because both 10 - 7 == 3 and 7 - 4 == 3. 
Example 2:*/


class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        
      if(nums.size() < 3 ) return 0;
      int  Modified  = 2*diff;
        
       map<int,int> mp;
        
        int count=0;
        for(int i =0 ; i < nums.size() ; i++)
        {
            int val = nums[i] - Modified;
            
            if(val >= 0 and mp.find(val) != mp.end())
            {
                int midVal = nums[i] - diff;
                if(mp.find(midVal) != mp.end()) 
                count++;
            }
            
            mp[nums[i]]++;
        }
        
        return count;
        
    }
};
