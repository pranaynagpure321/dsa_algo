class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
       // if(nums.size() ==0) return {};
        vector<string> res;
        int left =lower , right  = 0;
        for(int i = 0 ;i <nums.size(); i++)
        {
            left = lower;
            right = nums[i]-1;
            
            if(nums[i] -left >0 )
            {
                if(left == right && left != nums[i])
                res.push_back(to_string(left));

                else if(right > left)
                res.push_back(to_string(left) +"->" +to_string(right));
            }
            lower = nums[i] +1;
        }


        if((upper - lower) >=0 )
        {
            if(lower == upper)
            res.push_back(to_string(upper));

            else
            res.push_back(to_string(lower) + "->" + to_string(upper));
        }

        return res;
    }
    
};
