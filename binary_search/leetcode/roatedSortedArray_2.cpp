class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        
        int min = 0, max = nums.size()-1;
        
        while(min <= max)
        {
            int mid = (min + max ) >> 1;
            
            if(nums[mid]== target ) return true;
            
            if(nums[min] <= nums[mid])
            {
                if(target >= nums[mid] )
                    min = mid + 1;
                else
                    max = mid - 1;
            }
            else
            {
                
                if(target < nums[mid])
                    max = mid - 1;
                else
                    min = mid + 1;
                
            }
                
        }
        
        
        return false;
    }
};
