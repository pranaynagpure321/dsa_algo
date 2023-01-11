class Solution {
public:
    vector<vector<int>> res; 
    void dfs(vector<int>& candidates,vector<int>&tmp, int t,int idx)
    {
        if(t==0 )
        {
            res.push_back(tmp);
            return;
        }
        for(int i =idx ;i< candidates.size(); i++)
        {
            if(t - candidates[i]>=0)
            {
                tmp.push_back(candidates[i]);
                dfs(candidates,tmp,t- candidates[i],i);
                tmp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
          vector<int> tmp;
           dfs(candidates,tmp, target,0);

        return res;
    }
};
