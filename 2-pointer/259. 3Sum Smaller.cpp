 int threeSumSmaller(vector<int>& nums, int target) {
        
        int n = nums.size();
        int count = 0;
        int ans = 0;
        sort(nums.begin(), nums.end());
        
        for(int  k =0 ;k < n -2  ; k++ )
        {
            int l = k+1 , r = n-1;
            
            int t = target - nums[k];
            
            while(l < r)
            {
                if(t <= nums[l] + nums[r])
                    r--;
                else 
                {
                    count+=r-l;
                    l++;
                }
                
            }
        }
        return count;
        
    }
