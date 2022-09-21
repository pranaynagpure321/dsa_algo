class Solution {
    public int[] singleNumber(int[] nums) {
         int xor =0 ;

        for (int a: nums) {
            xor ^= a;
        }
        int bitmaks = xor & (-xor);                  // trick to take take rightmost bit only
        
        int x =0;
        for (int a  : nums)
        {
            if((a & bitmaks)!=   0)                  // this will seperaate numbers in 2 gps baded on if rightmost bit is set
                x^=a;                                
        }

        return new  int[]{x,x^xor};                 //in x we will get first number and x^xor will give us remaining number
    }
}
