class Solution {
public:
    
    int getDigitSum(long long n)
    {
        int sum = 0;

        while (n)
        {
            sum += n % 10;
            n /= 10;
        }

        return sum;
    }
    long long makeIntegerBeautiful(long long n, int target) {
       
        if (getDigitSum(n) <= target) return 0;
        long long p  =1;
        long long diff = 0;

        while (n > 0 )            // 10251
        {
            p *= 10;      // p= 10

            diff = p - n%p;
            int sum = getDigitSum(n + diff);

            if (sum <= target)
                return diff;
            
        }
        return 0L;
    }
};
