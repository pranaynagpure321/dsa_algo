class Solution {
public:

    // (Sum (nums)) %p = (pfix(i)-pfix(j))% p
    // (Sum(nums)) %p  = r
    // r = (pfix(i) - pfix(j))%p
    // np + r = (pfix(i) - pfix(j))%p
    //pfix(j)%p  = (pfix(i)%p - Sum(nums)%p)%p
    int minSubarray(vector<int>& nums, int p) {
        
       int sum =0, ans = nums.size();

       for(int &i : nums)
       sum  = (sum%p + i%p)%p;

       if(sum %p == 0) return 0;
        
       unordered_map<int,int> mp;
       int prefix_sum =0;
       mp[0] =-1;
       
       for(int i =0 ;i< nums.size();++i)
       {
           prefix_sum = (prefix_sum%p + nums[i]%p)%p;

           int key = (prefix_sum%p - sum%p+p)%p;

           if(mp.count(key))
           {
               ans = min(ans, i - mp[key]);
           }

           mp[prefix_sum%p] = i;
       }
        return ans < nums.size() ? ans : -1;

    }
};
