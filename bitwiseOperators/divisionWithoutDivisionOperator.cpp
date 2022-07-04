if( B==0) return  INT_MAX;
    if(B== 1) return A;
    if(B==-1 && A>0) return B*A; 
    if(B==-1 && A==INT_MIN) return INT_MAX;
    int  sign = ((A<0) ^ (B<0)) ?-1:1;
 
    //cout<<"HI"<<sign;
    int q=0; 
    
    long long divisor = abs((long long)A); 
    //cout<<"\nhi"<<divisor<<endl;
    long long dividend = abs((long long)B); 
    while(divisor>=dividend)
    {
        divisor -=dividend;
        q++;
    }
    return q*sign;
