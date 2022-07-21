class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
         int i = 0 ; 
        int j = 0;

        int sum =nums[0];
        int ans = nums.size() + 1;

        int n = nums.size();

        while (i< n && j < n)
        {
            if(sum < target)
            {
                j+=1; if(j == n) break;
                sum += nums[j];

            }

            if(sum >= target)
            {
                if(j-i < ans) ans = j-i;

                sum -= nums[i];
                i +=1;
            }

        }

         if(ans > nums.size()) return 0;

        return ans+1;
    }
};
