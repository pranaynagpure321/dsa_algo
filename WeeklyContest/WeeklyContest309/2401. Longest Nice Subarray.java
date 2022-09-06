/*2401. Longest Nice Subarray
User Accepted:3918
User Tried:6118
Total Accepted:4083
Total Submissions:12078
Difficulty:Medium
You are given an array nums consisting of positive integers.

We call a subarray of nums nice if the bitwise AND of every pair of elements that are in different positions in the subarray is equal to 0.

Return the length of the longest nice subarray.

A subarray is a contiguous part of an array.

Note that subarrays of length 1 are always considered nice.

 

Example 1:

Input: nums = [1,3,8,48,10]
Output: 3
Explanation: The longest nice subarray is [3,8,48]. This subarray satisfies the conditions:
- 3 AND 8 = 0.
- 3 AND 48 = 0.
- 8 AND 48 = 0.
It can be proven that no longer nice subarray can be obtained, so we return 3.*/

class Solution {
    public int longestNiceSubarray(int[] nums) {
        
       int max = 0, i = 0;

        int  tempor = 0;
        for (int j = 0; j < nums.length; j++) {

            while ((tempor & nums[j]) !=0 )
                tempor ^= nums[i++];

            tempor |= nums[j];
            max = Math.max(j - i +1 , max);

        }
        return  max ;
    }
}
