 

unsigned int Solution::reverse(unsigned int A) {
     
    if(A==0) return 0;
    unsigned int ans=0;
    int i=0;
    while(A>0)
    {
        ans  = ans<<1;
       
        if((A&1)==1)
        {
           ans ^=1;
        }
        
        A>>=1;i++;
    }
    i=32-i;
    ans <<= i;
    
    return ans; 
}
