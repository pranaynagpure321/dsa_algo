/*7. Reverse Integer
Medium

7957

10402

Add to List

Share
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

Example 1:

Input: x = 123
Output: 321
Example 2:

int reverse(int x) {
        int ans = 0;
        while (x) {
            int temp = ans * 10 + x % 10;
            if (temp / 10 != ans)
                return 0;
            ans = temp;
            x /= 10;
        }
        return ans;
    }


*/


class Solution {
public:
    
    int reverse(int x) {
        
        int sign = x>0 ? 1 : -1;
        
        int ans =0;
        
        int max  = 147483647;  //to check overflow
        
        string xstr = sign >0 ? to_string(x) : to_string(x).substr(1) ;
        
        
       for(int i = 0 ;i<xstr.length() ; i++)
       {
            int digit = (xstr[i] - '0');
           
            if(  i >=8) {    //overflow condition
             
                if(digit >= 2  and ans >= max ) return 0;
            
            }   
           
            ans  += digit * pow(10,i);
       }
        
        return sign*ans;
         
    }
};
