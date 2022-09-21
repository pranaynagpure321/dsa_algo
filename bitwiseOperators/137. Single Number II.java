class Solution {
    public int singleNumber(int[] nums) {
        
        int[] bits = new int[33];
        for (int i = 0; i < nums.length; i++) {

            int n = nums[i];
            if(n<0)               //set 32nd bit if number is less than zero
            {
                bits[32]++;
                n = -1*n;
            }
            int bitmask = n;
            for(int j =0; j<32 ;++j)             //count every bit in number
            {
                if(  (1 & bitmask) != 0)        //and with 1 to check if bit is set or not
                {
                    bits[j]++;
                }
                
                bitmask>>= 1;
                if(bitmask ==0) break;             //break if all bits are gone
            }
        }
        long result =0;
        for (int i = 0; i < 32; i++) {

            if(bits[i]%3 ==1)                           //ALL THE 3thrice number will be set bits will be in 3 multiple
            result += Math.pow(2,i);                // recreate number with set bits
        }

        if(bits[32]%3!=0)
            return (int)result*-1;
        return (int)result;
    }
}
