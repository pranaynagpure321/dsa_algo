class Solution {
public:

    vector<int> count,res;

    int dfs( vector<vector<int>>& adj, vector<bool>& vis,int node )
    {
        vis[node] = true;
       // count[node]++;
        for(int i : adj[node])
        {
            if(!vis[i])
            {
                count[node] += 1+dfs(adj,vis,i );
                res[node] +=  res[i] + count[i];
            }
        }
        vis[node] = false;
        return count[node];
    }

    void dfs_2( vector<vector<int>>& adj, vector<bool>& vis,int root )
    {
        vis[root] = true;
        for(int i : adj[root])
        {
            if(!vis[i])
            {
                res[i] = res[root] -count[i] + count.size() -count[i];
                dfs_2(adj,vis,i);
            }
        }

        vis[root] = false;
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {

       vector<vector<int>> adj(n,vector<int>());

       for(auto &e: edges)
       {
           adj[e[0]].push_back(e[1]);
           adj[e[1]].push_back(e[0]);
       }
       vector<bool> vis(n,false);
       count.resize(n,0);
       res.resize(n,1);
       dfs(adj,vis,0);

       for(int i=0 ;i< count.size();i++)
       {
            --res[i];
            ++count[i];
       }


       dfs_2(adj,vis,0);
       return res;
      
      //time O(N)

    }
};
