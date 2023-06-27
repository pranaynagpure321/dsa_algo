class Solution {
public:
    vector<vector<int>> dp; 
    int dfs(vector<vector<int>>& triangle, int idx, int previdx)
    {
        if(idx >= triangle.size()) return 0;
        if(dp[idx][previdx] != -1) return dp[idx][previdx];
        return dp[idx][previdx] = min( triangle[idx][previdx]+ dfs(triangle,idx+1,previdx), triangle[idx][previdx+1] + dfs(triangle, idx+1, previdx+1) );

    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        dp = vector<vector<int>>(n ,vector<int>(n,-1));
        return triangle[0][0] + dfs(triangle,1,0);
    }
};
