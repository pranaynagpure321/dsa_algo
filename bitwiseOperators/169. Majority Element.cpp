class Solution {
public:
    int majorityElement(vector<int>& nums) {
      
        int n = nums.size();
        int ans =0;
        
        for(int i =0 ;i<32 ;i++)
        {
            int bit_cnt =0;
            int bit = (1<<i);
            for(int a : nums)
                if(a & (bit))
                    bit_cnt++;
            
            if(bit_cnt>n/2)
                ans |= bit;
        }
        
        return ans;
    }
};
