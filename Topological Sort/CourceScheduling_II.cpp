class Solution {
public:
    vector<int> findOrder(int N, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj (N, vector<int>());

        for (auto& v : prerequisites)
        {
            adj[v[1]].push_back(v[0]);
        }

        vector<int> indeg(N, 0);

        for (auto& v : adj)
        {
            for (auto& i : v)
            {
                indeg[i]++;
            }
        }

        queue<int> q;

        for (int i =0 ;i< N ;i++)
        {
            if (indeg[i] == 0)
                q.push(i);
        }


        vector<int> topo;

        while (!q.empty())
        {
            int start = q.front();
            q.pop();

            topo.push_back(start);


            for (auto& i : adj[start])
            {
                indeg[i]--;

                if (indeg[i] == 0)
                    q.push(i);
            }
        }

        if (topo.size() == N)
            return topo;

        return {};


    }
};
