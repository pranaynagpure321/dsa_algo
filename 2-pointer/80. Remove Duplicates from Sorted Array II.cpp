int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 2) return nums.size();
        
        int i =0 ,count =0 ,k=0, j =0 ;
        int ele = nums[0];
        int n = nums.size();
        
        for( j =0 ;j<=nums.size() ; j++)
        {

            if(j<n and nums[j] == ele) count++;

            else
            {
                if(count >= 2)
                {
                    nums[i++] = ele;
                    nums[i++] = ele;
                }

                else
                {
                    nums[i++] = ele;
                }

                if(j<n)
                ele = nums[j];
                count=1;
            }

        }

        return i;
    }
