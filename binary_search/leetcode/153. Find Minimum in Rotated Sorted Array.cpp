class Solution {
public:
     int getrotationIndex(vector<int> &nums)
    {
        if(nums.size()<2 || nums[0]<nums[nums.size()-1] ) return -1;

        int i=0 , n = nums.size(), j=n-1;

        while (i<=j)
        {
            int mid = (i+j)>>1;

            if(nums[mid]>nums[mid+1])
                return mid;

            else
            {
                if(nums[mid]<nums[i])                   //check if smaller than start then move left or right
                    j = mid-1;
                else i= mid+1;
            }
        }

        return -1;
    }
    
    int findMin(vector<int>& nums) {
          int peakIdx = getrotationIndex(nums);
        
        //time O(logn)
        //space O(1)

        return peakIdx==-1?nums[0]:nums[peakIdx+1];
    }
};
