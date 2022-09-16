/*162. Find Peak Element
Medium
Share
A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.*/

class Solution {
    public int findPeakElement(int[] arr) {
        
        if(arr.length < 3)
        {
            if(arr.length == 1)
            {
              return 0;  
            }
            
            if(arr[0]> arr[1]) return 0;
            
            return 1;
        }
         int i =0 ,j = arr.length-1;

        while ( i <= j )
        {
            int mid = (i+j)>>1;

            if(mid-1> 0 && mid+1<arr.length && arr[mid]>arr[mid-1] && arr[mid]> arr[mid+1])
            {
                return mid;
            }
            if(mid-1>=0 && arr[mid-1]>arr[mid])
                j= mid-1;
            else i= mid+1;
        }


        return i-1;
    }
}
