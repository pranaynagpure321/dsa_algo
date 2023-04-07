class Solution {
public:

    void dfs(vector<vector<int>>& grid, int i , int j , int& m , int& n)
    {
        if( i<0 || j<0 || i>=m || j>=n || grid[i][j] !=0 ) return;
        
        grid[i][j] =1;

        dfs(grid, i-1 , j, m,n);
        dfs(grid, i+1 , j, m,n);
        dfs(grid, i , j-1, m,n);
        dfs(grid, i , j+1, m,n);
    }

    int closedIsland(vector<vector<int>>& grid) {
        
        int m = grid.size(), n= grid[0].size(),cnt=0;
      
        //this dfs call is to mark all the boundry 0=>1 because these are not islands
        for(int i =0 ;i < m; i++)
        {
            for(int j =0 ;j< n; j++)
            {
                if((i*j ==0 || i == m-1 || j ==n-1 ) && grid[i][j] == 0)
                {
                    dfs(grid, i , j, m,n);
                }
            }
        }

        //then call dfs on remaining 0s which are actual islands
        for(int i =1; i<m-1; i++)
        {
            for(int j = 1 ; j< n-1 ;j++)
            {
                if(grid[i][j] == 0){
                 dfs(grid, i , j, m,n);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
