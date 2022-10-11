class Solution {
public:
   
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
          //build tree
    // delete leaf nodes one by one until there are either 2 or 1(odd case) nodes are left because those are the centoid of tree and would have minimum hight tree.
        
        if(n<2)
        {
            vector<int> ans;
            for(int i=0;i<n;i++)
                ans.push_back(i);
            
            return ans;
        }
        
        vector<vector<int>> adj(n, vector<int>());

        for (auto& edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }


        vector<int> leaves;

        for (int i = 0; i < n; i++)
        {
            if (adj[i].size() == 1)
                leaves.push_back(i);
        }

        int remainingnodes = n;   //delete leaf nodes one by one
        while (remainingnodes> 2)    
        {
            remainingnodes -= leaves.size();
            vector<int> newLeaves;
            for (int leaf : leaves)
            {
                int neighbour = adj[leaf].front();
                adj[leaf].pop_back();

                auto &v = adj[neighbour];

                //get iterator to relement and then remove the value from vector
                auto it = find(v.begin(), v.end() , leaf);
                if(it != v.end())
                    v.erase(it);
                if (adj[neighbour].size() == 1)
                    newLeaves.push_back(neighbour);
            }

            leaves = newLeaves;
        }
      
        return leaves;
    }
};
