static bool cmp( vector<int> &a ,vector<int> &b )
    {
        if(a[0] == b[0])
        return a[1] > b[1];

        return a[0] < b[0];
    }

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& inter) {
        
        sort(inter.begin(), inter.end(),cmp);

        int cnt =0;

        int start =inter[0][0], end = inter[0][1];

        for(int i =1; i< inter.size(); ++i)
        {

            if(inter[i][0]<=end and  inter[i][1]<= end )
            cnt++;

            else
                start = inter[i][0], end = inter[i][1];
            
        }
        return inter.size() - cnt;
    }
};
