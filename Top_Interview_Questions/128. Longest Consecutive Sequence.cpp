class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       
       if(nums.size() ==0) return 0;
       unordered_map<int,bool> mp;
       int mi = nums[0], mx= nums[0];
       for(int &a :nums)
       {
           mp[a]= true;
       }

      int  count =0;
      for(auto &pair : mp)
      {
        int a = pair.first;
        int tmpcnt =0;
        int num = a;
        if(!mp.count(a-1))
        {
            tmpcnt++;
            while(mp.count(num+1))
            {
                tmpcnt++; num++;
            }
            count = max(count,tmpcnt);
        }

      }
       // time O(N) used hasmap to check if cureent elemnt is start of sequence
       // above condition is checkd using if curelement-1 exist in map 
        return count;
    }
};
