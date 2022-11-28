class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
     // if(k ==0 ) return 0;
      map<int , int> mp;
      mp[0] =1;
      int sum =0,res=0;
      for(int i =0 ;i<nums.size() ;i++)
      {
        sum +=  nums[i];

        if(mp.count(sum -k))
         res += mp[sum-k];

        mp[sum]++;
      }

      return res;
    }
};
