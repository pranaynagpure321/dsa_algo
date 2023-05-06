class Solution {
public:
    int mod = 1e9 + 7;
    int numSubseq(vector<int>& nums, int target) {
       sort(nums.begin(), nums.end());

        int left =0, right =nums.size()-1,res =0, n = nums.size();
        vector<int> power(n);
        power[0]=1;
        for(int i=1 ;i<n ;i++)
        {
            power[i] = (power[i-1]*2)%mod;
        }

        while(left <= right)
        {
            if(nums[left] + nums[right] > target)
            right--;

            else
            {
                res = (res%mod +power[ right-left]%mod)%mod;
                left++;
            }
        }
       
        return res;
    }
};
