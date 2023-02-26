class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
      
        int rsum =0;
        for(int i =0 ; i< nums.size(); i++)
        {
            rsum+=nums[i];
        }
        int lsum=0,t=0;
        for(int i =0 ;i< nums.size() ; i++)
        {
            t = nums[i];
            rsum -= t;
            nums[i]  = abs(lsum-rsum);
            lsum += t;
        }
        
        return nums;
        
    }
};
