class Solution {
public:
    

    bool isValid(vector<int>& v1, vector<int>& v2)
    {
        if (v1[0] == v2[0]) return true;
        if (v1[1] == v2[1]) return true;

        return false;
    }


    void dfs(vector<vector<int>>& stones, vector<bool>& vis, int idx)
    {
        vis[idx] = true;


        for (int i = 0; i < stones.size(); i++)
        {
            if (!vis[i] && isValid(stones[i], stones[idx]))
            {
                dfs(stones, vis, i);
            }
        }
    }


    int removeStones(vector<vector<int>>& stones) {

        int n = stones.size();

        vector<bool> vis(n, false);

        int connectedComponents = 0;

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
                dfs(stones, vis, i),connectedComponents++;
        }
        return n - connectedComponents;
    }
};
