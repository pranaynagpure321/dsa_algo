 
int Solution::solve(int A) {

   //bitset<32> bset1(A);
 if(A==0) return 0;

   long count =0;
   int x=0;
  
    while ((1<<x) <= A)
    {
      x++;
    }
    x-=1;
  //formula (2^(x-1)) * x + A- 2^x + 1 + solve(A- 2^x); 
  count += ((x * (1<<(x-1)))+ (A-  (1<<x) + 1)  + solve(A-(1<<x)))% 1000000007;
  return count ;   
}
