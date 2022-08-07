/*2368. Reachable Nodes With Restrictions
User Accepted:7722
User Tried:9328
Total Accepted:7887
Total Submissions:16676
Difficulty:Medium
There is an undirected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.

You are given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree. You are also given an integer array restricted which represents restricted nodes.

Return the maximum number of nodes you can reach from node 0 without visiting a restricted node.

Note that node 0 will not be a restricted node.

 

Example 1:


Input: n = 7, edges = [[0,1],[1,2],[3,1],[4,0],[0,5],[5,6]], restricted = [4,5]
Output: 4
Explanation: The diagram above shows the tree.
We have that [0,1,2,3] are the only nodes that can be reached from node 0 without visiting a restricted node. */


class Solution
{
public:
    void dfs(int u, vector<int> adj[], int &cnt, vector<bool> &vis)
    {
        vis[u] = true;
        // if we reach a new node, while performing dfs, we increase our count by 1
        cnt++; 
        for (auto v : adj[u])
        {
            if (vis[v] == false)
            {
                dfs(v, adj, cnt, vis);
            }
        }
    }
    int reachableNodes(int n, vector<vector<int>> &edges, vector<int> &restricted)
    {
        vector<bool> visited(n, false);
        vector<int> adj[n]; // adjency list
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        for (auto a : restricted)
        {
            visited[a] = true; // marking the restricted nodes  as visited.
        }
        int count = 0;
        dfs(0, adj, count, visited);
        return count;
    }
};
