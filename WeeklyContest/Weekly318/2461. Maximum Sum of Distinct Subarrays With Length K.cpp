class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        map<int, int> mp;

        int  count =0 , j =0;
        long long kSum =0, mx=0;

        for (int i = 0; i < nums.size(); i++)
        {
            
            mp[nums[i]]++;
            kSum += nums[i];
            count++;
            

            if (i + 1 >= k) {

                if (count > k)
                {
                    kSum -= nums[j]; count--;
                    if (mp[nums[j]] > 1)
                       mp[nums[j++]]--   ;
                    else
                        mp.erase(nums[j++]);
                }

                if (mp.size() == k and count == k)
                {
                    mx = max(mx, kSum);
                }
                
               
            }
           // cout<<"i => "<<i << " arr value=>  "<<nums[i]<<" map size => "<<mp.size() <<" count =>" << count<<" kSum=> "<<kSum<<endl;
        }

    
        return mx;
    }
};


//some useful tc for the question
/*[1,5,2,2,9,9,9,6,7,3,2,5,2,4,12,12,12,13,3,5,12,7,9]
5
[1,5,2,2,9,9,9,6,7,3,2,5,2,4,12]
5
[1,5,2,2,9,9,9,6,7,3,2,5,2,4,12]
4
[1,5,2,2,9,9,9,6,7,3,2,5,2,4,12]
3
[1,5,4,2,9,9,9]
3
[4,4,4]
3*/
