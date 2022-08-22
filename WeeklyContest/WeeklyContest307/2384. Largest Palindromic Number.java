/*2384. Largest Palindromic Number
User Accepted:4680
User Tried:6923
Total Accepted:4803
Total Submissions:21355
Difficulty:Medium
You are given a string num consisting of digits only.

Return the largest palindromic integer (in the form of a string) that can be formed using digits taken from num. It should not contain leading zeroes.

Notes:

You do not need to use all the digits of num, but you must use at least one digit.
The digits can be reordered.
 

Example 1:

Input: num = "444947137"
Output: "7449447"
Explanation: 
Use the digits "4449477" from "444947137" to form the palindromic integer "7449447".
It can be shown that "7449447" is the largest palindromic integer that can be formed. */


public String largestPalindromic(String num) {
        
        int[] cnt = new int[11];
        for( var c : num.toCharArray() ) cnt[c- '0']++;

        String lp="",rp="", ans= "";

        for ( int i = 9 ;i>=0 ; i--)
        {

            if(lp.length() == 0  && i ==0) continue;   //check size of left partition if its 0 and  i=0 then do not add 
            if(cnt[i] > 1  ) //add only if count of i number is greater than 1
            {
                while(cnt[i] > 1 )
                {
                    lp +=   i;   //add to both left and right and reduce count by2
                    rp +=   i;
                    cnt[i] -=2;

                }
            }
        }

        for(int i = 9 ; i>= 0 ; i--)
        {
            if(cnt[i] >0)
            {
                lp += i;break;  //then take largest with count == 1 and break;
            }
        }
        StringBuilder sb=new StringBuilder(rp);
        sb.reverse();   // reverse right and add and return
        //System.out.println(lp  );
        //System.out.println(rp);
        //System.out.println();
        return lp+ sb;
           
    }
