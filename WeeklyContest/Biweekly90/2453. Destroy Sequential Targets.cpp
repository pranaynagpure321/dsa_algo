class Solution {
public:
    // used property where remainder of all the number in ap is same 
    //     Input: nums = [3,7,8,1,1,5], space = 2
    // Output: 1
    // Explanation: If we seed the machine with nums[3], then we destroy all targets equal to 1,3,5,7,9,...  // this form AP with space as command difference
    // In this case, we would destroy 5 total targets (all except for nums[2]). 
    // It is impossible to destroy more than 5 targets, so we return nums[3].
    int destroyTargets(vector<int>& nums, int space) {
        int mx =0;
        int num = INT_MAX;
        map<int, int> mp;
         
        for (int i = 0; i < nums.size();i++ )
        {
            int a = nums[i];
            mp[a % space]++;
            mx = max(mp[a % space], mx);
        }
        cout << "hi mx => " << mx<<endl;
        for (int a : nums)
            if (mp[a % space] == mx)
                num = min(num, a);
        cout << "hello end";
        return num;
        
    }
};
