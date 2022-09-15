/*Find the minimum difference element in a sorted array
Given an array of integers sorted in ascending order, and a target value, find the element in the array that has minimum difference with the target value.

Example 1:

Input: a[] = [2, 5, 10, 12, 15], target = 6
Output: 5
Explanation: The difference between the target value '6' and '5' is the minimum. 
Example 2:

Input: a[] = [2, 5, 10, 12, 15], target = 5
Output: 5
Example 3:

Input: a[] = [2, 5, 10, 12, 15], target = 8
Output: 10
Example 4:

Input: a[] = [2, 5, 10, 12, 15], target = 11
Output: 10
Example 5:

Input: a[] = [2, 5, 10, 12, 15], target = 20
Output: 15*/ 
 
 public int minimumDifferenceElementinSortedArray(int[] a , int target)
    {
        int n = a.length;

        if (target < a[0])
            return a[0];
        if (target > a[n - 1])
            return a[n - 1];

        int start = 0, end = n - 1;
        while (start <= end) {
            int mid = (start + end) / 2;

            if (target == a[mid]) {
                return a[mid];
            } else if (target < a[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        /*
           At the end of the while loop, 
           a[start] is the ceiling of target (Smallest number greater than target), and 
           a[end] is the floor of target (Largest number smaller than target).
           
           Return the element whose difference with target is smaller
         */
        if ((a[start] - target) < (target - a[end]))
            return a[start];
        return a[end];


    }
