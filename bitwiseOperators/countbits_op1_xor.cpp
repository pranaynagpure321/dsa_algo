int countbits(int n)
{
    int ans=0;

    while (n>0)
    {
       ans++;
       n &= (n-1);
    }
    return ans;
}
 

int Solution::cntBits(vector<int> &A) {
    
    int n1= A.size();
     int ans=0;
     
    for (int i = 0; i < n1; i++)
    {
       for(int j=i+1; j<n1 ;j++ )
       {
           ans+= 2*countbits(A[i] ^ A[j]);
       }
    }
    
    return ans;
}
