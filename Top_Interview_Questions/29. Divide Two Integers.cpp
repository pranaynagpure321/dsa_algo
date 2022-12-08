#define ll long long
class Solution {
public:
    //video solution
    //https://www.youtube.com/watch?v=m4L_5qG4vG8&ab_channel=AlgorithmsMadeEasy
    int divide(int dividend, int divisor) {
        if(dividend == INT_MAX && divisor == -1) return -INT_MAX;
        if(dividend == INT_MAX && divisor == 1) return INT_MAX;
        if(dividend == INT_MIN && divisor == 1) return INT_MIN;
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        
        int sign  = (dividend<0) ? -1:1;
        sign = (divisor<0)? -sign : sign;
        ll n =  abs(dividend);
        ll d  = abs(divisor);

        int result =0;
        while(n - d >=0)
        {
            int cnt =1;
            while((n - (d<<cnt)) >=0)     // count how many doubles of divisor can be accomodate inside current dividend
            {
                cnt++;
            }
            result += 1<<(cnt-1);      // shift bit and add that many doubles inside the result
            n -= d<<(cnt-1);           // reduce numerator by cnt-1 times the divisor
        }

        // time (log dividend)
        //example
        /*
        n = 200 d=7

        n= 200 d = 7 14 28 56 112  cnt  =5;
        result += 1<<(cnt-1)  => 16

        n= 88 d = 7  14 28 56 cnt = 4
        res += 1<<(cnt-1)  => 24

        n= 32 d = 7  14 28   cnt = 3
        res += 1<<(cnt-1)  => 28

        */
        return  (sign ==-1) ? -result: result;
    }
};
