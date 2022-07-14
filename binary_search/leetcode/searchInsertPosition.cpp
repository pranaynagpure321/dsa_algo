class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int min = 0 , max = nums.size()-1;
        
        if(target < nums[0] ) return 0;
        
        if( target > nums[nums.size()-1]) return nums.size();
        
        
        while(min <= max )
        {
            
            int mid = (min + max) >> 1;
            
            
            if(nums[mid] == target) return mid;
            
    
            if(nums[mid] < target)
                min = mid +1 ;
            else
                max = mid - 1;
            
        }
        return min;
        
        
    }
};
