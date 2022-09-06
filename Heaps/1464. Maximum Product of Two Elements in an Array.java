class Solution {
    public int maxProduct(int[] nums) {
         PriorityQueue<Integer> pq = new PriorityQueue<Integer>(Collections.reverseOrder());
        
        for ( int a : nums) 
            pq.add(a);
        
        return (pq.poll()-1)*(pq.poll()-1);
    }
}
