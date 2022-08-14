/*2373. Largest Local Values in a Matrix
User Accepted:9124
User Tried:9512
Total Accepted:9276
Total Submissions:11250
Difficulty:Easy
You are given an n x n integer matrix grid.

Generate an integer matrix maxLocal of size (n - 2) x (n - 2) such that:

maxLocal[i][j] is equal to the largest value of the 3 x 3 matrix in grid centered around row i + 1 and column j + 1.
In other words, we want to find the largest value in every contiguous 3 x 3 matrix in grid.

Return the generated matrix.

 

Example 1:


Input: grid = [[9,9,8,1],[5,6,2,6],[8,2,6,4],[6,2,2,2]]
Output: [[9,9],[8,6]]
Explanation: The diagram above shows the original matrix and the generated matrix.
Notice that each value in the generated matrix corresponds to the largest value of a contiguous 3 x 3 matrix in grid. */




class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
         int n = grid.size();
    vector<vector<int>>  ans(n-2,vector<int>(n-2));

    set<int> s;


    for(int i =1 ;i<=n-2 ;i++ )
    {   

        for(int j =1 ; j<=n-2 ;j++)
        {
            int res = max(grid[i][j],  max(grid[i-1][j-1], grid[i+1][j+1]));
            res =    max(res,  max(grid[i-1][j],grid[i+1][j])  );
            res = max ( res, max(grid[i-1][j+1], grid[i+1][j-1]) );
            res = max(res, max(grid[i][j-1],grid[i][j+1]));

            ans[i-1][j-1]= res;
        }
    }


    return ans;
    }
};
