class Solution {
    public int countPrimeSetBits(int L, int R) {
         int count = 0;
    while (L <= R)
        //count += 665772 >> __builtin_popcount(L++) & 1;     for cpp
        count += 665772 >> Integer.bitCount(L++) & 1;
    return count;
    }
    
    
    // 665772 is your lookup table which has 2 ,3 ,5,7,11,13,17,19 bit set is left shift of that number is true then number is prime and return count
}
