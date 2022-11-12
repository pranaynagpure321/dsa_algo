/*2386. Find the K-Sum of an Array
Hard

196

6

Add to List

Share
You are given an integer array nums and a positive integer k. You can choose any subsequence of the array and sum all of its elements together.

We define the K-Sum of the array as the kth largest subsequence sum that can be obtained (not necessarily distinct).

Return the K-Sum of the array.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

Note that the empty subsequence is considered to have a sum of 0.

create mean heap and interate only those nodes where ans in minimum



*/


class Solution {
    public long kSum(int[] nums, int k) {
     long minus = 0, sum = 0;
      
        for(int i =0 ;i< nums.length ;i++) {
            if(nums[i] >0 )
            sum += nums[i];
            if(nums[i]< 0) nums[i] =Math.abs(nums[i]);
        }

        Arrays.sort(nums);  
        var q = new PriorityQueue<long[]>(Comparator.comparingLong(o -> o[0]));
        q.add(new long[]{nums[0], 0});
        while(--k>0){  
            long[] top = q.poll();
            int i = (int)top[1]++;
            long val = top[0];
            minus = val;
            if (i < nums.length-1){  
                top[0] += nums[i+1];
                q.offer(new long[]{val - nums[i] + nums[i+1], i+1});
                q.offer(top);
            }
        }
        return sum - minus;
    }
}
