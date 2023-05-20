class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());

        int mi = INT_MAX;

        for(auto &v : intervals)
        {
            if(mi!= INT_MAX and mi > v[0]   ) return false;
            if(mi!= INT_MAX and v[0] < mi ) return false;
            mi = v[1];
        }
        return true;
    }
};
