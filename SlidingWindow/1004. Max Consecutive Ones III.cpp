class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i =0, j, onecnt =0, zerocnt =0 , res =0;
        
        for( j =0 ;j < nums.size() ; ++j )
        {
            if(nums[j] == 1  ) onecnt++;
            else
            zerocnt++;

            while(  i <= j and zerocnt  > k)
            {
                if(nums[i] == 1  ) onecnt--;
                else
                    zerocnt--; i++;
            }

            if(zerocnt <= k)
            res = max(res , zerocnt+onecnt);
        }
        return res;
    }
};
