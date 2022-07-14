class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        
        
        int min = 0;
        int max = nums.size()-1;
        vector<int> v{ -1 ,-1};
        if(nums.size() == 0 ) return v;
        
        
        while(min <= max)
        {
            int mid = (min + max) >> 1;
           
            if(nums[mid] < target)
                min = mid +1 ;
            
            else
                max = mid - 1;
        }
        
        if( min < nums.size() && nums[min] == target)
        {
            int i = min , j=min, forwardPosition = min , backwardPosition = min;
           
            while( nums[i] == target )
            {
                forwardPosition = i;
                i+=1;
                
                if(i == nums.size()) break;
            }
            
            while(  nums[j] == target)
            {
                backwardPosition = j;
                j-=1;
                
                  if(j <0) break;
            }
            
            v[0] = backwardPosition;
            v[1] = forwardPosition;
        }
        
      
            return v;
        
        
    }
};
