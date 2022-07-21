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




//#another solution with more understtandable way O(N)

int  minSubArrayLen_3(int target, vector<int>& nums)
{
    int left =0 , j =0;

    int sum =0; int ans = INT_MAX;
    
    for( ; j< nums.size() ; j++)
    {
       sum += nums[j];

       while (sum >= target)
       {
          ans = min(ans, j+1-i);
          sum -= nums[left++];
       }
       
    }

  return ans == INT_MAX ? 0: ans;

}
