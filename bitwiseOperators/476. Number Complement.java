class Solution {
public:
    int findComplement(int n) {
        
       if(n==1 ) return 0;
        int size = (int)(log2(n))+1;
        long long bitmask = (1L<<size) -1;
        return n ^ bitmask;
    }
};



class Solution {
    public int findComplement(int num) {
         int mask = ~0;
        while ((num & mask)>0) mask <<= 1;
        
        //time O(1)
        return ~mask & ~num;
    }
}


//both solution have time O(1)
