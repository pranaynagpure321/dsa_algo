class Solution {
public:
    int concatenatedBinary(int n) {
        
        const int mod = 1000000007;
        int len = 0;
        long res =0;
        
        for(int i =1; i<= n ;i++)
        {
            if( (i & (i-1) ) ==0 )        //update shift length only when we see power of 2
                len++;
            
            res = ((res << len) + i ) %mod;
        }
        
        //time O(n)
        return res;
    }
};


// java solution
class Solution {
    public int concatenatedBinary(int n) {
        int mod = 1000_00_000_7;
        long num =0;
        
        for(int i =1; i<= n ;i++)
        {
            
           int a =i;
           int len = (int)(Math.log(a) / Math.log(2) + 1);
           num <<=len;
           num = num %mod;
           num += i; 
        }
        
        //time nlogn
        return (int)num;
    }
}
