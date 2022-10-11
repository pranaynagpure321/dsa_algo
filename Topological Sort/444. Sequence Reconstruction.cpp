class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int  N = nums.size();
        vector<vector<int>> adj(N+1, vector<int>());

       for (auto& v : sequences)               //build the graph
        {
            for (int i = 1; i < v.size(); i++)
            {
                adj[v[i-1]].push_back(v[i]);             // eample [1,2,3] mens 1->2->3 
            }
        }
        vector<int> indeg(N+1, 0);                   //calculate indgree

        for (int i = 1; i < N + 1; i++)
        {
            for (auto& a : adj[i])
            {
                indeg[a]++;
            }
        }

        queue<int> q;                                     // do topo sort on graph anywhere if we found 2 nodes
        for (int i = 1; i < N+1; i++)                      // in queue then we can return the false as there would be multiple paths
        {
            if (indeg[i] == 0)
                q.push(i);
        }
        vector<int> topo;
        while (!q.empty())
        {
            if (q.size() > 1)return false;

            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (int a : adj[node])
            {
                indeg[a]--;
                if (indeg[a] == 0)
                    q.push(a);
            }
        }

        if (topo.size() != nums.size())
            return false;

        return true;
        // time O(N)
    }
};
