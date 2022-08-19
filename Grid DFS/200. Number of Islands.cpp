/*200. Number of Islands
Mediu
Share
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
 
  */
  
  class Solution {
public:
    
    void dfs(vector<vector<char>>& grid, int i ,int j, int& m , int& n)
    {
        
        grid[i][j] = '0';
        
        if(i-1 >= 0 and grid[i-1][j] == '1' )
            dfs(grid,i-1,j,m,n);
        if(i+1 < m  and grid[i+1][j] == '1'  )
            dfs(grid,i+1,j,m,n);
        
        if(j-1 >= 0  and grid[i][j-1] == '1'  )
            dfs(grid,i,j-1,m,n);
        
        if(j+1 < n  and grid[i][j+1] == '1'  )
            dfs(grid,i,j+1,m,n);
        
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        int ans =0;
        
        int m = grid.size();
        int n = grid[0].size();
        for(int i =0 ;i< grid.size(); i++)
        {
            for(int j =0 ; j< grid[i].size(); j++)
            {
                if(grid[i][j] == '1')
                {
                    dfs(grid,i,j, m,n);
                    ans++;
                    
                    cout<<i<<" "<<j<<endl;
                }
            }
        }
        
        return ans;
    }
    
    
    //time (M x N)
};
