class Solution {
public:
    int brightestPosition(vector<vector<int>>& lights) {
        
        int n = lights.size();
        vector<int> start(n,0),end(n,0);
        int i =0;
        for(auto &v : lights)
        {
            start[i] = v[0] - v[1];
            end[i++] = v[0] + v[1];
        }

        sort(start.begin(), start.end());
        sort(end.begin(),end.end());
         
        int max_b=0  , idx =0, curr_b=0,j=0, k= 0;
        
       
       while(j< start.size())
       {
           int currentstart = start[j];
           int currentend = end[k];

           if(currentstart <= currentend)
           {
               j++;
               curr_b++;
           }
           else
           {
               k++;
               curr_b--;
           }

           if(curr_b> max_b)
           {
               max_b = curr_b;
               idx = currentstart;
           }
       }

        return idx;
    }
};
