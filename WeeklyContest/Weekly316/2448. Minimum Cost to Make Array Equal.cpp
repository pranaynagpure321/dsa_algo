class Solution {
public:
    long long getCost(vector<int>& nums, vector<int>& cost, int target)
    {
        long long ans = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            ans += 1L*abs(target - nums[i]) *cost[i];
        }

        return ans;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int   mx=1000000, mn =1;
        long long res = LONG_MAX;
        
        while (mn < mx)
        {
            //get mn cost 
            int mid = (mn + mx) >> 1;

            long long midCost = getCost(nums, cost, mid);
            long long mid1Cost = getCost(nums,cost,mid+1);
            res = min(res,min(midCost,mid1Cost));

            if (midCost<mid1Cost)
            {
                mx = mid -1;
            }
            else {
                mn = mid + 1;
            }
        }

        return res;

    }
};
