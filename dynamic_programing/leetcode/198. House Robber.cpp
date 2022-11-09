int rob(vector<int>& nums) {
        vector<int>  dp (nums.size(), -1);

        int n = nums.size();
        if(n==0) return 0;
        int next =0;
        int nextPlusOne = 0;

        for(int i = 0 ; i< n ;i++)
        {
           int curr = max(nextPlusOne,next+nums[i]);
           next= nextPlusOne;
           nextPlusOne =  curr;
        }


        return nextPlusOne;
    }
