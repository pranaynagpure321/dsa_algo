class Solution {
public:
    double myPow(double x, int n) {
       
      if(n==0) return 1;
      if(n<0)   // optimization beast 100% solution before division is always better as number is small
      {
        x = 1/x;
      }
      int p = abs(n);
      double res = x; //2 4 16
      double carryPower = 1.0;

      while(p>1)
      {
          // cout<<" res =>" <<res<<" p=> "<<p<<endl;
          if(p%2 !=0)
          {
            carryPower = res*carryPower;   
          }
          
          res *=res;  
          p /=2;   
      }

      res *= carryPower;
      //time O(logn)

      return res;
    }
};
