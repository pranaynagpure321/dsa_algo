class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
    
        int mi = INT_MAX, mx = INT_MIN , mi_idx =-1, mx_idx =-1;
        int n = nums.size();

        for(int i=0 ;i< n; ++i)
        {
           if(nums[i]<mi)mi = nums[i], mi_idx =i;
           if(nums[i] >= mx) mx = nums[i], mx_idx = i;
        }
      
        bool freeswap = mi_idx > mx_idx; // if index is small index is smaller the one free swap would be there 
        int minswap = n - 1 - mx_idx;
        return  mi_idx + minswap - freeswap;
    }
};
