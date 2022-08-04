/*You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

 

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]] */


class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> merged;
        
        if(intervals.size() == 0){   intervals.push_back(newInterval);return intervals;}
        
        int a = newInterval[0];
        
        int i =0;
        
        for( ;i< intervals.size() ; i++)
        {
            if(a >  intervals[i][0])
                merged.push_back(intervals[i]);
            else
                break;
        }
        
        
        int count = merged.size() ;
        
        if(  merged.empty() || newInterval[0] > merged[count-1][1])
        {
            merged.push_back(newInterval); 
        }
            
        else
        {
            merged[count-1][1] = max(newInterval[1],merged[count-1][1] );
            count--;
        }
        
        for( ; i<intervals.size() ; i++  )
        {
            if( intervals[i][0] > merged[count][1])
            {
                merged.push_back(intervals[i]); count++;
            }
            else
            {
                merged[count][1] = max( intervals[i][1], merged[count][1]);
            }
        }

        
        return merged;
    }
};
