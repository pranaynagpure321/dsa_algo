class Solution {
public:

    int getOR(vector<int> &bit_vec)
    {
        int ans  =0;
        for(int i =0 ; i<32 ; i++)
        {
            if(bit_vec[i] >0)
            {
                ans = ans | (1<<i);
            }
        }
        return ans;
    }
    vector<int> smallestSubarrays(vector<int>& nums) {
        
        vector<int> bit_vec(32,0); // create a bit vector to saves bit count
        vector<int> res((int)nums.size(), 1); // result
        int OR =0;

        for(int &i : nums)  // maximum or possible in array
        OR = OR |i;

        int j =0 , i =0;

        for(j =0 ;j< nums.size(); ++j) // sliding window until the end
        {
            int a = nums[j];
            int k =0;
            while(a)      // add the bits to number like if 3 the bit_vec[0]++ and bit_vec[1]++ as 3's binary is 11
            {
                if(a & 1)
                bit_vec[k]++;
                a >>=1;
                ++k;
            }

            while(i <=j and getOR(bit_vec) >= OR)   // incremtn i until you find the maxinmum xor
            { 
                res[i] = j-i+1;
                
                a= nums[i]; k=0;
                while(a)     // similar to adding bits we can remove the bits from the vector
                {
                    if(a & 1)
                    bit_vec[k]--;
                    a >>=1;
                    ++k;
                }
                i++;
            }

        }

        //rest array or
        if(i< nums.size()) //if i<nums.size() then call the funtion again as the array is till unsolved
        {
            vector<int> t(nums.begin()+i,nums.end());
            auto v = smallestSubarrays( t);

            for(int k = i ;k< nums.size() ; k++)
            {
                res[k] =v[k-i];
            }
        }

        return res;
    }
};
