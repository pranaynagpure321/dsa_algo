class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        
      if(nums.size() < 3 ) return 0;
      int  Modified  = 2*diff;
        
       map<int,int> mp;
        
        int count=0;
        for(int i =0 ; i < nums.size() ; i++)
        {
            int val = nums[i] - Modified;
            
            if(val >= 0 and mp.find(val) != mp.end())
            {
                int midVal = nums[i] - diff;
                if(mp.find(midVal) != mp.end()) 
                count++;
            }
            
            mp[nums[i]]++;
        }
        
        return count;
        
    }
};
