/*744. Find Smallest Letter Greater Than Target
Easy

Share
Given a characters array letters that is sorted in non-decreasing order and a character target, return the smallest character in the array that is larger than target.

Note that the letters wrap around.

For example, if target == 'z' and letters == ['a', 'b'], the answer is 'a'.
 
Example 1:

Input: letters = ["c","f","j"], target = "a"
Output: "c"
Example 2:

Input: letters = ["c","f","j"], target = "c"
Output: "f" */

class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
       
        int n=letters.length, i =0 , j = n -1;
        if((int)target >= (int)letters[n-1] || (int)target < (int)letters[0]) return letters[0];


        while (i <= j)
        {
            int mid = (i+j)>>1;

            if(letters[mid] <= target)
                i = mid+1;
            else j = mid-1;

        }
        return letters[i];
    }
}
