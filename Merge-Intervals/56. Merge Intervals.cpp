class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        
        vector<vector<int>> v;
        
        for(int  i =0 ;i < intervals.size() ; i++ )
        {
            int a = intervals[i][0];
            int b = intervals[i][1];
            for(int j = i+1 ; j < intervals.size() ; j++)
            {
                if(b >= intervals[j][0] )
                {   
                    if(b < intervals[j][1])
                    b = intervals[j][1]; 
                    i++;
                }
                else{
                    
                    break;
                }
            }
            
            v.push_back({a,b});
        }
        
        return v;
    }
};
