/*435. Non-overlapping Intervals
Medium

4488

132

Add to List

Share
Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

 

Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping. */

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() < 2 ) return 0;
        
        sort(intervals.begin(), intervals.end());
        
        
        int count = 0, last_included=0;
        for(int i =1 ;i < intervals.size() ; i++)
        {
            if(intervals[i][0] < intervals[last_included][1])
            {
                count++;
                
                if(intervals[i][1] < intervals[last_included][1] ) last_included = i;
            }
            
            else
            {
                last_included = i;
            }
        }
        
        return count;
    }
};
