/*239. Sliding Window Maximum
Hard

You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7  */


class Solution {
    
    
    public int[] maxSlidingWindow(int[] nums, int k) {
        
                                                                                             
          int[] ans = new int[nums.length - k + 1];                                          

          ArrayDeque<Integer> dq = new ArrayDeque<>();                                       
            int j =0;                                                                        
          for(int i =0 ;i<nums.length  ; i++)                                                
          {                                                                                  

              while ( !dq.isEmpty() && dq.peekFirst() < (i-k+1))     dq.pollFirst();           //remove all the first elements from dq which are out of range  

              while ( !dq.isEmpty() && nums[ dq.peekLast()] < nums[i])              // to maintain decresing order remove all those which are less that current element          
              {                                                                              
                  dq.pollLast();                                                             
              }                                                                              
              if(dq.isEmpty()) dq.addLast(i);                       // if dq is empty then just add that element                          

              else if(nums[i] <= nums[ dq.peekLast()] )             //if current element is less than or equal dq last elemnt then add to last                          
                  dq.addLast(i);                                                             

              if(i +1 >= k && !dq.isEmpty())                                                 // get first element of dq
              {                                                                              
                  ans[j++] = nums[dq.peekFirst()] ;                                          
                 // System.out.print(nums[dq.peekFirst()] + " ");                            
              }                                                                              

          }                  
        
        
        //time O(n)
        //space O(n)
          return ans;                                                                        
    }
}
