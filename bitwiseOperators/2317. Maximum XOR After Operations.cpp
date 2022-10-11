class Solution {
public:
    int maximumXOR(vector<int>& n) {
        
        int XOR =0; vector<int> bits(32,0);
        
        for(int i =0 ;i< n.size() ; i++)  //count number of bits all the numbers
        {
            int a = n[i];
            int  k=0;
            while(a)
            {
                if(a & 1)
                    bits[k]++;
                a>>=1;k++;
            }
        }
        int num =0;
        for(int i =0 ;i< 32 ; i++)           // then set the bit based on count found
        {
           int ch = bits[i];
           if(ch % 2 !=0 )                     // if count is odd then just set bit in number
               num |= (1<<i);
           if(ch!=0 and ch % 2 ==0 )        // count should not be zero and divisible by 2 then only set bit
               num |= (1<<i);
        }
        
        
        //time O(N)
        return num;
        
    }
};
