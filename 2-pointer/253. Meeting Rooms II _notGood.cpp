
/*Given an array of meeting time intervals intervals where intervals[i] = [starti, endi], return the minimum number of conference rooms required.

 

Example 1:

Input: intervals = [[0,30],[5,10],[15,20]]
Output: 2 */




class Solution {
    
    bool isRoomFree(  vector<int> & meetings, int start , int end)
    {  
        //to check collusion of meeting with existing meetins in room
        
        for(int m =0 ; m<meetings.size() ; m+=2)
        {
            if(start == meetings[m] or end == meetings[m+1]) return false;
            
            else if( (meetings[m] < start and  start < meetings[m+1] )  or  ( meetings[m] < end and end < meetings[m+1] ) )
            {
                return false;
            }
        }
        
        return true;
    }
    
    
    bool isAnyRoomFree ( int &room , map<int,  vector<int> > & mp, vector<int>& v)
    {
          for(int i = 1; i<= room ; i++)
          {
              
              if(isRoomFree(mp[i], v[0] ,v[1] ))  //to check if anymeeting in that room collides with new meeting
              {
                 mp[i].push_back(v[0]);
                 mp[i].push_back(v[1]);
                  return true;
                  
              }
          }
        
        room++;
        mp[room].push_back(v[0]);
        mp[room].push_back(v[1]);
        
        return false;
    }
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        if(intervals.size()== 1) return 1;
        
        sort(intervals.begin() , intervals.end());
        
        map<int ,  vector<int>> mp;  //map to store rooms and meetings vector
         
        int count =1;
        auto first = intervals[0];
        
        mp[count].push_back(first[0]);
        mp[count].push_back(first[1]);
        
        for(int i = 1 ;i<intervals.size() ; i++)
        {
             isAnyRoomFree(count, mp, intervals[i]);   //check if any room in map is free to accomodate any meeting
        }
        
        return count;
    }
};
