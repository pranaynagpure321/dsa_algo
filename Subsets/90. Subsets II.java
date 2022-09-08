/*90. Subsets II
Medium

6502

183

Add to List

Share
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]    */

class Solution {
    public  List<List<Integer>> subsetsWithDup(int[] nums) {
        
        Arrays.sort(nums);                   //sort the nums array to remove duplicates
        Set< List<Integer>> set = new HashSet<>();           //create to store all the generated subsets
        int n = nums.length;
        int size = (int)Math.pow(2,n);
        for (int i =0 ;i<size ;i++)
        {
          List<Integer> l1 = new LinkedList<>();

            for(int j =0 ;j<n ;j++)
            {
                if((i & (1<<j)) > 0 )
                    l1.add(nums[j]);
            }
            //Collections.sort(l1);                    // this wawe can avoid duplicate sets , but sort once is better option
            set.add(l1);
        }

        var ans = new LinkedList<List<Integer>>();            //add the generated subsets to list

        for( var m : set)
        {
            //m.forEach(System.out::print);
            //System.out.println();
            ans.add(m);
        }
        System.out.println("size => "+ans.size());
        
        //time  (n 2^n) n is size of arr     
        return ans;
    }
}
