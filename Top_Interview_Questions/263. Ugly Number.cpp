class Solution {
public:
 
    bool isUgly(int n) {
        if(n<=0 ) return false;
       //divide by two
        while(n%2 ==0 and  n>1)
        {
            n = n/2;
        }

        //divide by 3

         while(n%3 ==0 and  n>1)
        {
            n = n/3;
        }

          while(n%5 ==0 and  n>1)
        {
            n = n/5;
        }
       

        return n==1;
    }
};
