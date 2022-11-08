#define ll long long
class Solution {
public:
 long long dfs_2(vector<int>& robot, vector<vector<int>>& factory, int i, int j, int k,vector<vector<vector<ll>>>& dp) {

        if (i == robot.size()) return 0;

        if (j == factory.size()) return 1e16;

        if (dp[i][j][k] != -1) return dp[i][j][k];

        ll nottake = dfs_2(robot, factory, i, j + 1, 0,dp);
        ll take = (k < factory[j][1] )? (abs(robot[i] - factory[j][0]) + dfs_2(robot, factory, i + 1, j, k + 1,dp)): 1e16;

        return dp[i][j][k]= min(take, nottake);
    }
    
    
    
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        
        sort(robot.begin(), robot.end());

        sort(factory.begin(), factory.end());

         
        vector<vector<vector<ll>>> dp( robot.size() , vector<vector<ll>>(factory.size(), vector<ll>(robot.size() , -1) ));

        // 3dimention dp 1st is robots index, 2nd facotry index, 3rd is limit of factory
        return dfs_2(robot,factory,0,0,0,dp);
    }
};
