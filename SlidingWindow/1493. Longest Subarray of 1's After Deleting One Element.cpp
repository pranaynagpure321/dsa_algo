class Solution {
public:
    int longestSubarray(vector<int>& nums) {

       int i =0, j=0;
       int mx = 0, cnt =0;
       for( ;j< nums.size(); ++j)
       {
           if(nums[j] == 0) cnt++;

           while(cnt>1)
           {
               if(nums[i] == 0) cnt--;
               ++i;
           }

           mx = max(j-i+1,mx);
       } 
       return mx-1;
    }
};
