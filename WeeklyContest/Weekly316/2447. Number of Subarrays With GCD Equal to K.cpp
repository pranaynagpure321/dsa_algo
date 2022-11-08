class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n and nums[j]%k ==0; j++)
            {
                  nums[i] = gcd(nums[i], nums[j]);
                ans += k == nums[i];
            }

        }
        
        return ans;
    }
};
