/*202. Happy Number
Easy

6205

791

Add to List

Share
Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

 

Example 1:

Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1 */


class Solution {
public:
    
    int getNext(int n)
    {
        int ans  =0;
        
        while(n!=0)
        {
            int digit  = n%10;
            ans += digit*digit;
            n = n/10;
        }
        
        return ans;
    }
    bool isHappy(int n) {
         
        int tortoise =  n ; 
        int hare =  n;
        
        if(n == 10 or n == 100 or n == 1000) return true;
        
        while(tortoise != 1 and hare != 1)
        {
            tortoise = getNext(tortoise);
            hare = getNext(getNext(hare));
            
            if(hare == tortoise)
                return false;
        }
        
        return true;
    }
};
