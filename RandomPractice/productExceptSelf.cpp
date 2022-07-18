class Solution {
public:
    
    
    int division(int a , int b)
    {
        int sign = (a<0) ^ (b<0) ? -1 : 1;
        
        long dividend = abs(a);
        long divisor = abs(b);
        long quo = 0 , temp =0;
        for(int i = 31; i>=0 ;i--)
        {
            if(temp + (divisor<<i) <= dividend)
            {
                temp += divisor<<i;
                quo |= 1L<<i;
            }
            
        }
        
        return quo*sign;
    }
    
    vector<int> productExceptSelf(vector<int>& nums) {
        
        long product =1;
        int CountZeros = 0;
        
        for(int i = 0 ;i< nums.size() ; i++ )
        {
            if(nums[i] != 0)
            {
                product *= nums[i]; 
            }
            else
                CountZeros++;
        }
        
        if(CountZeros==1)
        for(int i =0 ;i<nums.size() ;i++)
        {
            if(nums[i] != 0)
            nums[i] = 0;
            
            else
                nums[i] = product;
        }
        
        
        if(CountZeros >= 2)
            for(int i =0 ;i<nums.size() ;i++)
            {
                nums[i] = 0;
            }
        
        
       if(CountZeros == 0)
       {
         for(int i =0 ;i<nums.size() ;i++)
        {
             
            nums[i] =  division(product, nums[i]);
            
             
        }
       }
        return nums;
    }
};
