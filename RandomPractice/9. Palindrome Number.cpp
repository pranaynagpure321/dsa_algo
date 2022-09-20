class Solution {
public:
    bool isPalindrome(int x) {
        
       if(x<0 || ( x!=0 && x%10==0)) return false;
        
       int rev =0 ;
        
        while(rev<x)                // do loop until  half only because of overflow
        {
            rev = rev*10 + x%10;
            x /= 10;
        }
        
        return (rev == x) || (rev/10 ==x);           // two condition one for check even palindrom other fro odd paildrome
    }
};
