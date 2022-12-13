class Solution {
public:

   
    void dfs(vector<vector<int>>& grid2, vector<vector<bool>>& vis,int row, int col,vector<pair<int,int>> & island)
    {
        if(row<0 || col <0 || row>= grid2.size() || col >= grid2[0].size() || vis[row][col] || grid2[row][col]==0) return;

        vis[row][col] = true;

        island.push_back({row,col});

        dfs(grid2,vis,row-1,col,island);
        dfs(grid2,vis,row+1,col,island);
        dfs(grid2,vis,row,col-1,island);
        dfs(grid2,vis,row,col+1,island);

    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        int m = grid2.size(), n =grid2[0].size();
        vector<vector<bool>> vis (m, vector<bool>(n, false));
         vector<vector<pair<int,int>>> grid2Islands;

        for(int i =0 ;i< m ;i++)
        {
            for(int j =0 ;j<n ;j++)
            {
                if(grid2[i][j] ==1 && vis[i][j] ==false)
                {
                    vector<pair<int,int>> tmpIsland;
                    dfs(grid2,vis,i,j,tmpIsland);
                    grid2Islands.push_back(tmpIsland);
                }
            }
        }

        int res =0;bool flag = true;
        for(auto & isl : grid2Islands)
        {
            flag = true;
            for(auto &p : isl)
            {
                if(grid1[p.first][p.second]==0) {
                    flag = false;
                    break;
                }
            }

            if(flag)
            res++;
        }

        return res;
    }
};
