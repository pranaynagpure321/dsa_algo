/*852. Peak Index in a Mountain Array
Medium

Share
An array arr a mountain if the following properties hold:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given a mountain array arr, return the index i such that arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].

You must solve it in O(log(arr.length)) time complexity.

 

Example 1:

Input: arr = [0,1,0]
Output: 1*/


class Solution {
    public int peakIndexInMountainArray(int[] arr) {
        
        int i =0 ,j = arr.length-1;

        while ( i <= j )
        {
            int mid = (i+j)>>1;

            if(mid-1> 0 && mid+1<arr.length && arr[mid]>arr[mid-1] && arr[mid]> arr[mid+1])
            {
                return mid;
            }
            if(mid-1>0 && arr[mid-1]>arr[mid])
                j= mid-1;
            else i= mid+1;
        }


        return i-1;
    }
}
