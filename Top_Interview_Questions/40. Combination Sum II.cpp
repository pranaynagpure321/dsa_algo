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
        
        if(t<0 || idx>= candidates.size()) return;


        for(int i =idx ;i< candidates.size(); i++)
        {
            if (i > idx && candidates[i] == candidates[i - 1])
                continue;
            if(t - candidates[i]>=0)
            {
                tmp.push_back(candidates[i]);
                dfs(candidates,tmp,t- candidates[i],i+1);
                tmp.pop_back();
            }
        }
    }
        

    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
         vector<int> tmp;
        sort(candidates.begin(),candidates.end()  );
         dfs(candidates,tmp, target,0);

        return res;
    }
};
