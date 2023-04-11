class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
      
        int sum =0, rem =0;
        int cnt =0; 
        unordered_map<int,int> mp; //used property where when remainder is found again means we found subarray with given condition
        mp[0]=1;
        for(int i =0 ; i< nums.size(); i++)
        {
            sum += nums[i];
            rem = sum%k ;
            if(rem < 0)
            {
                rem += k;
            }
            if(mp.find(rem) != mp.end())
            {
                cnt += mp[rem];
            }
            mp[rem]++;
        }
        return cnt;
    
    }
};
