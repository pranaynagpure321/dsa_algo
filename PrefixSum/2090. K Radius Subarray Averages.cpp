class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<long long > n2(n);

        for(int i =0 ; i< n ;++i)
        n2[i] = nums[i];

        for(int i =0 ; i< n ;++i)
         nums[i] = -1;
        
        if(2*k + 1 > n ) return nums;

        for(int i =1 ;i< n ; ++i)
        n2[i] += n2[i-1];

        for(int i = k ; i< n-k ; ++i)
        {
            long long sum = n2[i+k];
            if( i - k -1 >= 0)
            sum -= n2[i - k -1];

            sum /= (2*k +1);

            nums [i] =sum;
        }

        return nums;
    }
};
