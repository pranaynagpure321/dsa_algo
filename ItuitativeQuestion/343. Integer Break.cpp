class Solution {
public:
int getPower(int a, int b)
{
    if(b == 1) return a;
    int  k= a;
    while(b>1)
    {
        a *=k;
        b--;
    }
    return a;
}
    int integerBreak(int n) {
       
    int res =1, i= 2;
    if(n ==  3) return 2;
    while(n/i >= 2)   // 50
    {
        int q = n/i; //  q = 20/3 = 3^6 * 2
        int rem = n%i;

        if( q*i == n )
        {
            res = max(res, getPower(i,q));
        }
        else
        {
            if(rem == 1)
            {
                int po = getPower(i, q-1);
                res = max(res , po*(rem+i));
                //res = max(res ,  )
            }
            else{
                int po = getPower(i, q);
                res = max(res , po*rem);
            }
           
        }
        i++;
    }
        return res;
    }
};
