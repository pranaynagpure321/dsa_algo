class Solution {
public:

// use multiset to maintain the sorted order and check the first and last element diff to increase or decrese the window
    int longestSubarray(vector<int>& nums, int limit) {
        
        multiset<int> set;
        int i=0 ,j=0;
        for( j =0 ;j< nums.size(); j++)
        {
            set.insert(nums[j]);

            if(*set.rbegin() - *set.begin() > limit)
            set.erase(set.find(nums[i++]));
        }

        return j - i;
    }
};
