class Solution {
public:
    pair<int,int> bfs(vector<vector<int>> adj, int u,int n )    //bfs to interate on graph
    {
        queue<int> q;
        q.push(u);
        vector<bool> vis(n + 1, false);
        int len = 0 , lastnode =0;

        while (!q.empty())
        {
            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                int node = q.front();
                q.pop();
                vis[node] = true;

                for (int nextnode : adj[node])
                {
                    if (!vis[nextnode])
                        q.push(nextnode);
                }
                lastnode = node;
            }
            len++;
        }

        return make_pair(len, lastnode);
    }

    int treeDiameter(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<vector<int>> adj(n + 1, vector<int>());

        for (auto edge : edges)
        {
            int u = edge[0] , v= edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        //first bfs to find farthest point       
        // run bfs twice to find the largest length in graph
        int farthest_node = bfs(adj, 0, n).second;               //get farthest node from zero
        cout<<"farthest_node => "<<farthest_node<<endl; 
        auto p = bfs(adj, farthest_node, n) ;                    // get second farthest node from first farthest nnode  that is u->v->w start from u find v start from v find w distace between v->w is longest distance      
        cout<<"second farthest node "<<p.second <<endl;
        return p.first-1;

    }
};
