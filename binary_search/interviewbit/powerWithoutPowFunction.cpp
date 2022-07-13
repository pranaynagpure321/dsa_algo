

int Solution::pow(int x, int n, int d) {
    
    if(x<0) return (x%d + d)%d;
    if(x==0) return 0;
    if(n==1) return x%d;

    long long ans=1, base=x;
    while (n>0)
    {
       if(n%2==1)
       {
            ans = (ans*base)%d;
            n-=1;
       }
       else
       {
            base = (base*base)%d;
            n /=2;
       }
    }

    return ans;
    
}
