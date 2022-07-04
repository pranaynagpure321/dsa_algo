int Solution::divide(int A, int B) {

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


}

int Solution::divide(int A, int B) {

    if( B==0) return  INT_MAX;
    if(B== 1) return A;
    if(B==-1 && A>0) return B*A; 
    if(B==-1 && A==INT_MIN) return INT_MAX;
    int  sign = ((A<0) ^ (B<0)) ?-1:1;
 
    
   long long dividend = abs((long long)A);
   long long divisor = abs((long long)B);
   int quo = 0,sum=0;

   for (int i = 31; i >=0 ; i--)
   {
    
       if((sum + (divisor << i)) <= dividend )
       {
            sum += divisor<<i;
            quo += 1<<i;
       }
      
   }
   
   return sign*quo;
}
