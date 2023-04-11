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

//java with same frequency operation
class Solution {
    public int subarraysDivByK(int[] nums, int k) {
        int[] counts = new int[k];
        int sum =0, rem =0;
        for(int i : nums)
        {
            sum +=i;
            rem = sum%k;
            if(rem< 0)
            {
                rem +=k;
            }
            counts[rem]++;
        }

        int res = counts[0];
        
        //below formula used to calculate if frequncey of remainder is greater than 2 then nC2 (n  is frequency)
        for(int i : counts)
        {
            res += (i*(i-1))/2;
        }
        return res;
    }
}
