/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
We are given a list schedule of employees, which represents the working time for each employee.

Each employee has a list of non-overlapping Intervals, and these intervals are in sorted order.

Return the list of finite intervals representing common, positive-length free time for all employees, also in sorted order.

(Even though we are representing Intervals in the form [x, y], the objects inside are Intervals, not lists or arrays. For example, schedule[0][0].start = 1, schedule[0][0].end = 2, and schedule[0][0][0] is not defined).  Also, we wouldn't include intervals like [5, 5] in our answer, as they have zero length.
Example 1:

Input: schedule = [[[1,2],[5,6]],[[1,3]],[[4,10]]]
Output: [[3,4]]
Explanation: There are a total of three employees, and all common
free time intervals would be [-inf, 1], [3, 4], [10, inf].
We discard any intervals that contain inf as they aren't finite.*/

class Solution {
public:
    
    void getMinMax(vector<vector<Interval>> &schedule,int & mi ,int &mx )
    {
        
        for(int i =0 ; i <schedule.size() ; i++ )
        {
            for(int j = 0 ; j< schedule[i].size() ; j ++)
            {
                mi = min(schedule[i][j].start, mi);
                mx = max(schedule[i][j].end, mx);
            }
        }
    }
    
    void markRange( vector<bool>& range , int start , int end)
    {
        for(int k = start ; k< end; k++)
        {
          range[k] = true;
        }
    }
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        
        vector<Interval> ans;
        
        int mi = INT_MAX;
        int mx = INT_MIN;
        
        getMinMax(schedule,mi , mx);
        vector<bool> range(mx+1, false);
        
        for(int i =0 ; i <schedule.size() ; i++ )
        {
            for(int j = 0 ; j< schedule[i].size() ; j ++)
            {
                markRange(range, schedule[i][j].start, schedule[i][j].end);
            }
        }
        
        for(int k =mi ;k < range.size() ; )
        {
            if(!range[k])
            {
                int m = k;
                while(!range[m] and  m<range.size()) m++;
                
                if(m < range.size())
                {
                    Interval inter(k, m);
                    ans.push_back(inter);
                }
                
                k = m;
            }
            else k++;
        }
        
        return ans;
        
    }
};
