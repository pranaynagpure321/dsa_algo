class Solution {
public:
    vector<vector<long long>> dp;
    int help(vector<int>& pp , int k, int cnt, int idx)
    {
        if(idx >= pp.size() || cnt == 0)
        {
            return 0;
        }
        if(dp[idx][cnt] != -1)
        return dp[idx][cnt];

        int ans =0;
        ans  =  help(pp,k,cnt,idx+1);
        int it = upper_bound(pp.begin(),pp.end(), pp[idx]+k) - pp.begin();
        //take
        ans  = max(ans,  it - idx +  help(pp, k, cnt-1,it)  );
        //nottake
        
        return dp[idx][cnt]= ans;
    }

    int maximizeWin(vector<int>& pp, int k) {
        
        if(pp.size() == 2) return 2;
       // if(k ==0 and pp.size()>1) return 2;
        int n = pp.size();

        dp = vector<vector<long long>>(n,vector<long long>(3,-1));
        return help(pp, k, 2, 0);
    }
};
