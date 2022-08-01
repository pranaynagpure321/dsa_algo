/*Given an array of meeting time intervals intervals where intervals[i] = [starti, endi], return the minimum number of conference rooms required.

 

Example 1:

Input: intervals = [[0,30],[5,10],[15,20]]
Output: 2*/



class Solution {
    public int minMeetingRooms(int[][] intervals) {
        
        int[] start = new int[intervals.length];
        int[] end = new int[intervals.length];
        int m =0;
        for(var v: intervals)
        {
            start[m] = v[0];
            end[m++] = v[1];
        }
        
        Arrays.sort(start);
        Arrays.sort(end);
        
        int i =0 , j=0;
        int count=0 ;
        
        while( i < start.length)
        {
            
            // If there is a meeting that has ended by the time the meeting at `i` starts
           
            if(start[i] >= end[j])
            {
                j++;
                count--;
            }
            
              // We do this irrespective of whether a room frees up or not.
              // If a room got free, then this used_rooms += 1 wouldn't have any effect. used_rooms would
              // remain the same in that case. If no room was free, then this would increase used_rooms
            i++;
            count++;
            
        }
        
        return count;
        
    }
}
