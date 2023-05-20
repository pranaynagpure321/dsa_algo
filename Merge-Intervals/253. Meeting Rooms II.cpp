class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
      vector<int> start,end;

      for(auto &v : intervals)
      {
          start.push_back(v[0]);
          end.push_back(v[1]);
      }

      sort(start.begin(), start.end());
      sort(end.begin(), end.end());

      int i =0,j=0,cnt =0;
      while(i< start.size())
      {
        if(start[i] >= end[j])
        {
           j++;
           cnt--;
        }
        i++;
        cnt++;
      }

      return cnt;
    }
 };
