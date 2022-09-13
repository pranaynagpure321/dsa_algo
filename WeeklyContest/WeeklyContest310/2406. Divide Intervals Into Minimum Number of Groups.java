class Solution {
    public int minGroups(int[][] intervals) {
        
         Arrays.sort(intervals, Comparator.comparingInt(i->i[0])); // coparator to compare first value in array
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        for (int[] i : intervals)
        {
            if(!pq.isEmpty() && pq.peek() < i[0])                //check if top is less than start of curr interval
                pq.remove();
            
            pq.offer(i[1]);                                     // push end of new interval in min heap
        }
        
        return pq.size();
        
    }
}
