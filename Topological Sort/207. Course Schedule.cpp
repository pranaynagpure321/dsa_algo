
class Solution {
public:
    vector<vector<int>> adj;
    bool ans;

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }

    void dfs(deque<int>& st, vector<bool>& vis, int u)
    {
        vis[u] = true;

        auto nodes = adj[u];

        for (int i : nodes)
        {

            if (!vis[i])
            {
                dfs(st, vis, i);
            }


            else if (find(st.begin(), st.end(), i) == st.end())
            {
                ans = false;
                return;
            }
        }

        st.push_back(u);
        
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        adj = vector<vector<int>>(numCourses);
        
        ans  =true;

        for (auto& v : prerequisites)
        {
            addEdge(v[0], v[1]);
        }

        //do topo sort on adj
         //dfs topo sort

        deque<int> st;
        vector<bool> vis(numCourses, false);

        for (int i = 0; i < numCourses; i++)
        {
            if (vis[i] == false) {
             
                
                dfs(st, vis, i);

                if (ans == false) return false;
            }

        }

        return ans;


    }
};
