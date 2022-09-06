/*1338. Reduce Array Size to The Half
Medium

2751

131

Add to List

Share
You are given an integer array arr. You can choose a set of integers and remove all the occurrences of these integers in the array.

Return the minimum size of the set so that at least half of the integers of the array are removed.

 

Example 1:

Input: arr = [3,3,3,3,5,5,5,2,2,7]
Output: 2
Explanation: Choosing {3,7} will make the new array [5,5,5,2,2] which has size 5 (i.e equal to half of the size of the old array).
Possible sets of size 2 are {3,5},{3,2},{5,2}.
Choosing set {2,7} is not possible as it will make the new array [3,3,3,3,5,5,5] which has a size greater than half of the size of the old array. */


class Solution {
    public int minSetSize(int[] arr) {
        
        HashMap<Integer, Integer> mp = new HashMap<>();

        for( int i : arr)
        {
            mp.put(i , mp.getOrDefault(i,0)+1);
        }

        PriorityQueue<Pair<Integer,Integer>> pq = new PriorityQueue<>((a,b)-> b.getValue() - a.getValue());

        for (var key : mp.keySet())
        {
            pq.add(new Pair<>(key,mp.get(key)));
        }

        int len = arr.length;
        int count =0;
        int ans=0;
        while (  !pq.isEmpty() && count < len/2 )
        {
            var p = pq.poll();
            count += p.getValue();
            ans++;

        }
        //time nlogn
        //space o(2n)
        return ans;
    }
}
