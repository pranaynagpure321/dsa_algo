class Solution {
public:
    int averageValue(vector<int>& nums) {
         int cnt = 0, sum=0;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] % 6 == 0)
            {
                sum += nums[i];
                cnt++;
            }
        }


        return sum == 0 ? 0 : sum / cnt;
    }
};
