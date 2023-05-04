class Solution {
public:
    string predictPartyVictory(string s) {

        deque<int> rs, ds;
        int  n = s.size();
        for(  int i =0 ;i< s.size(); i++ )
        {
            if(s[i] == 'R')
            rs.push_back(i);

            else
            ds.push_back(i);
        }

        while(!rs.empty() and !ds.empty())
        {
            int r_front = rs.front(); rs.pop_front();
            int d_front =ds.front();    ds.pop_front();

            if(r_front < d_front)
            {
                rs.push_back(r_front+n);
            }
            else
            {
                ds.push_back(d_front+n);
            }
        }
        
        return rs.empty()? "Dire": "Radiant";
    }
};
