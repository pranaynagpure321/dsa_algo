class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        unordered_map<int, vector<pair<int,double>>> mp;
       
        for(int i =0 ; i< edges.size(); ++i)
        {
            mp[edges[i][0]].push_back({edges[i][1], succProb[i]});
            mp[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        queue<pair<int,double>> q;
        q.push({start,1});
        vector<double> dist(n,0.0);
        double prob = 0;

        while(q.size() >0)
        {
            auto node = q.front();q.pop();
            if(node.first == end)
            prob = max(prob, node.second);
            for(auto &nei : mp[node.first])
            {
                if(nei.second*node.second > dist[nei.first])
                {
                    q.push({nei.first,nei.second*node.second });
                    dist[nei.first] = nei.second*node.second;
                }
            }
           
        }
        return  prob;
    }
};
