/*96. Unique Binary Search Trees
Medium

Share
Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

 

Example 1:


Input: n = 3
Output: 5
Example 2:

Input: n = 1
Output: 1*/

class Solution {
public:
    int help(int n, vector<int> &dp)           //recusive
    {
        if(n==0 || n== 1)
            return 1;
        if(n==2)  return 2;

        if(dp[n] != -1 )
            return dp[n];

        int sum =0;

        for(int i =1 ;i <=n ;i++)
        {
            sum +=(help(i-1,dp ) * help(n-i,dp));                  //same recusive formula to generate catalan no
        }
        dp[n] = sum;

        return dp[n];
    }


    int numTrees(int n) {

        vector<int> dp(n+1);
        dp[0] =1;
        dp[1] =1;
        
        
        for(int i =2 ;i<=n ;i++)                                         //tabulation
        {
            for(int j =0 ;j < i ;j++)
            {
                dp[i] += dp[j] * dp[i-j-1]; //c4 = c0*c3 + c1*c2 + c2*c1+ c3*c0      formula to generate next catalan no
            }
        }
        
        //time O(n)
        //space for recussion O(N);
        //space for tabulation dp array of size N
        
        
        return dp[n];
    }
};
