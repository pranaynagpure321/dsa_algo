class Solution {
public: 
    int mx;
     bool isPossible_2(string &s,map<string, int>&mp,int i, int j, vector<int>& dp)
    {
        if(i >= s.length()) 
        {   
            return true;
        }

        if(dp[i] != -1) return dp[i] ;

        int k = j;
        string t = s.substr(i, k-i+1  );
        while(!mp.count(t) and  k<s.length())
        {
            k++;
            t = s.substr(i, k-i+1  ); if(t.length() > mx) return false;
        }
        if(k>= s.length() and !mp.count(t)) return false;
        cout<<t<<endl;
        
        
        bool   take = isPossible_2(s, mp, k+1, k+1,dp);
        if(take) return true;
        bool notTake = isPossible_2(s, mp, i, k+1,dp);
        dp[i]  = (notTake || take);
       //dp[i][j] = take;
        return   notTake ;

    }

    //bool dfs(string s, )

    bool wordBreak(string s, vector<string>& wordDict) {
        
        map<string, int>mp;
        mx =0;
        int n =s.length();
        //vector<vector<int>> dp(n, vector<int>(n,-1));
        vector<int> dp(n,-1);
        for(auto &tmp: wordDict)
        {
            mp[tmp]++;
            int len = tmp.length();
            mx = max(mx,len);
        }

        bool  ans = isPossible_2(s, mp, 0, 0,dp);

        return ans;
    }
};
