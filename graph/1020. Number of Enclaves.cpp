class Solution {
public:


    int dfs(vector<vector<int>>& grid, int i, int j  )
    {
        if(i<0 || j<0 || i>= grid.size() || j>= grid[0].size() || grid[i][j]==0) return 0;
        int res=0;
        grid[i][j] =0;
       res += dfs(grid,i-1,j);
       res += dfs(grid,i+1,j); 
       res += dfs(grid,i,j-1); 
       res += dfs(grid,i,j+1);
        return res+1;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        
        int m = grid.size(), n= grid[0].size();
        for(int i =0 ;i<grid.size();i++)
        {
            for(int j =0 ;j<grid[0].size();j++)
            {
                if((i==0 || j ==0 || i== m-1 || j== n-1) && grid[i][j]==1 )
                {
                    dfs(grid,i,j);
                }
            }
        }
        int res =0;
         for(int i =0 ;i<grid.size();i++)
        {
            for(int j =0 ;j<grid[0].size();j++)
            {
                if(  grid[i][j]==1 )
                {
                   res += dfs(grid,i,j);
                    
                }
            }
        }

        return res;
    }
};
