class Solution {
public:
     
    vector<int> dp;
    int getMahattan(vector<int> &p1 , vector<int> &p2)
    {
        return abs(p1[0]-p2[0]) + abs(p1[1]-p2[1]);
    }
     int dfs(vector<vector<int>>& workers, vector<vector<int>>& bikes,  int i,int mask )
    {
        if(i>= workers.size())
        {
            return 0;
        }

        if(dp[mask]!= -1) return dp[mask];

        int res =INT_MAX;
        for(int j = 0 ;j<bikes.size();j++)
        {    
            if( ( mask & (1<<j) ) == 0)
            {
                int t= getMahattan(workers[i], bikes[j]) +dfs(workers,bikes ,i+1, mask | (1<<j)) ;
               
                res = min(t,res);
            }
              
        }
        return dp[mask]=res;
    }

    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
  
       vector<bool> visBikes(bikes.size(),false);
    
        dp.resize(1024,-1);
        
        return dfs(workers,bikes ,0,0);
    }
};
