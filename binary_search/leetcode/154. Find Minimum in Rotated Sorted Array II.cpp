class Solution {
public:
     int getrotationIndex(vector<int> &nums)
    {
        
        int i=0 , n = nums.size(), j=n-1;

        while (i<j)
        {
            int mid = (i+j)>>1;
            
            if(nums[mid]<nums[j])                      // otherwise just do usual stuff
                    j = mid;
            else if(nums[mid]> nums[j])
                    i= mid+1;
            else j--;                             // if mid i and jth element are equal then we just decrement the j to just get closer to pivot
            
        }

        return nums[i];
    }
    int findMin(vector<int>& nums) {
        
        return  getrotationIndex(nums);
    }
};
