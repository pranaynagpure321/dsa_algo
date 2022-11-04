class Solution {
public:

    int dfs(vector<vector<int>>& matrix ,vector<vector<bool>>& vis, int i ,int j, vector<vector<int>> &dp )
    {
        if(vis[i][j]) return 0;

        if(i<0 || j<0 || i>=matrix.size() || j>=matrix[i].size()) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        vis[i][j]= true;
         //dfs in 4 direction
        int up =0, down =0, left = 0, right =0;

        if(i-1>=0 && matrix[i-1][j]>matrix[i][j])  
        up= 1+ dfs(matrix,vis,i-1,j,dp);

        if(i+1<matrix.size() && matrix[i+1][j]>matrix[i][j])  
        down = 1+ dfs(matrix,vis,i+1, j,dp);

        if(j-1>=0 && matrix[i][j-1]>matrix[i][j])  
        left = 1+ dfs(matrix,vis, i,j-1,dp);

        if(j+1<matrix[i].size() && matrix[i][j+1]>matrix[i][j])  
        right = 1+ dfs(matrix, vis,i,j+1,dp);

        vis[i][j] = false;
        dp[i][j]= max(up,max(down,max(left,right)));

        return dp[i][j];

    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
    
        vector<vector<bool>> vis( matrix.size(), vector<bool>(matrix[0].size(),false) );
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(),-1));
        int ans =0;
        for(int i =0; i<matrix.size(); i++ )
        {   
            int t =0;
            for(int j =0; j< matrix[i].size(); j++)
            {
                t = dfs(matrix,vis,i,j,dp);
                 ans = max(t,ans);
            }
             
        }

        return ans+1;
    }
};


// more understandable approach
class Solution {
public:
vector<vector<int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};
int m,n;
    int dfs(vector<vector<int>>& matrix , int i ,int j, vector<vector<int>> &dp )
    {
        if(dp[i][j]!=0) return dp[i][j];
         //dfs in 4 direction
        for(auto &v: dirs)
        {
            int x = i + v[0], y = j + v[1];
            if (0 <= x && x < m && 0 <= y && y < n && matrix[x][y] > matrix[i][j])
            dp[i][j]  = max(dp[i][j], dfs(matrix,x,y,dp));
        }
        return ++dp[i][j];

    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        m= matrix.size(); n= matrix[0].size();
        vector<vector<bool>> vis( m, vector<bool>(n ,false) );
        vector<vector<int>> dp(m, vector<int>(n,0));
        int ans =0;
        
        for(int i =0; i<m; i++ )
        {   
            int t =0;
            for(int j =0; j< matrix[i].size(); j++)
            {
                t = dfs(matrix, i,j,dp);
                ans = max(t,ans);
            } 
        }
        //o(mn)
        return ans;
    }
};
