int diffbits(int a, int b)
{
    int ans=0;
    for(int i =0 ;i<32 ;i++)
    {
        int mask = 1<<i;
        int abit=0,bbit=0;
        if(a & mask)
        abit=1;

        if(b & mask)
        bbit= 1;

        if(abit ^ bbit)
        ans++;
    }
   // cout<<"a=> "<<a<< " b=> "<<b<<"\tdiff=> "<<ans<<endl;
    return ans;
}

int Solution::cntBits(vector<int> &A) {
    
     int n1= A.size();
     int ans=0;
     
    for (int i = 0; i < n1; i++)
    {
       for(int j=i+1; j<n1 ;j++ )
       {
            ans += 2* diffbits(A[i],A[j]);
       }
    }
    
    return ans;
    
    
}
