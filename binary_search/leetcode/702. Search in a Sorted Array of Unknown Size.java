/*
702. Search in a Sorted Array of Unknown Size
Medium

This is an interactive problem.

You have a sorted array of unique elements and an unknown size. You do not have an access to the array but you can use the ArrayReader interface to access it. You can call ArrayReader.get(i) that:

returns the value at the ith index (0-indexed) of the secret array (i.e., secret[i]), or
returns 231 - 1 if the i is out of the boundary of the array.
You are also given an integer target.

Return the index k of the hidden array where secret[k] == target or return -1 otherwise.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: secret = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in secret and its index is 4. 


 * // This is ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface ArrayReader {
 *     public int get(int index) {}
 * }
 */

class Solution {
    public int search(ArrayReader reader, int target) {
            int i =0, j = 10000-1;

        while (i<= j)                    // search boundries of array
        {
            int mid = (i+j)>>1;

            int temp = reader.get(mid);

            if(temp == Integer.MAX_VALUE)
                j= mid-1;
            else
                i = mid+1;

        }

        int len = i;
        int min=0, max=len-1;
        
        while (min  <= max)                  //search element in that boundry
        {
            int mid = (min + max )>>1;
            
            int t = reader.get(mid);
            if(t == target) 
                return mid;
            
            if(t> target)
              max= mid -1;
            else min = mid +1;
        }
        
        return -1;
        
    }
}
