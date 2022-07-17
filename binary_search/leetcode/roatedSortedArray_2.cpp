#attempt 2


class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        
        int min = 0, max = nums.size()-1;
        
        while(min <= max)
        {
            int mid = (min + max ) >> 1;
            
            if(nums[mid]== target ) return true;
            
            if(nums[min] == nums[mid] && nums[mid] == nums[max])
            {
                min += 1;
                max -= 1;
            }
            else if(nums[min] > target)
            {
                if(nums[mid] > target)
                     max = mid - 1;
                else
                    min = mid + 1;
            }
            
            else
            {
                if(nums[mid] < target)
                     min = mid +1 ;
                else
                    max = mid -1;
            }
                
        }
        
        
        return false;
    }
};
