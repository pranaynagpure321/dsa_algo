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


  // by flipping the traingle anf keeping track of only single row insted 
  int minimumTotal(vector<vector<int>>& triangle) {
  
    int n = triangle.size();

    vector<int> next(n,0);

    for(int i =0 ; i< n ; ++i) next[i] = triangle[n-1][i];

    for(int i = n-2  ; i>=0 ; --i)
    {
        vector<int> curr(n,0);

        for(int j =0 ;j<= i ; j++)
        {
            int idx = triangle[i][j] + next[j];
            int idx2 = triangle[i][j] + next[j+1];
            curr[j]= min(idx,idx2);
        }
        next = curr;
    }
    return next[0];

    //timeO(n2) space O(N)
  }
};
