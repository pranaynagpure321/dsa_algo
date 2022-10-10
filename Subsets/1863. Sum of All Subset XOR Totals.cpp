class Solution {
public:
 
    int subsetXORSum(vector<int>& nums) {
      
        
        int n = nums.size();
        int size = pow(2,n);               
        int ans =0;
        for(int i =0 ;i <size ;i++)               // generate subset if bit is on in nums and the take xor or subset          
        {
            int tmp =0;
            for(int j = 0 ; j<n ;j++)                          
            {
                if(i & (1<<j))
                tmp ^= nums[j];                       
            }
            ans += tmp;                               
        }
        
        return ans;
    }
};
