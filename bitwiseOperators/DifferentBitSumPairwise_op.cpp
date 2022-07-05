

int Solution::cntBits(vector<int> &A) {
    
    int n = A.size();
    int ans=0;

    for(int i =0;i<31; i++)
    {
        long long zeros =0, ones=0; 
        for(int j =0 ;j<n ;j++)
        {
            if(A[j] & 1<<i)
            ones++;
            else
            zeros++;
            
        }

        ans+= (2*((ones *zeros)))%1000000007;
        
        //ans = ans % 1000000007;
        
       if(ans>=1000000007)ans-=1000000007;
    }

    return ans;
}
