typedef long long ll;

class Solution {
public:
    
    int res = INT_MAX;
    vector<int> dp;
    int dfs(string &s , ll k,int idx,  int sum, string prev)
    {

        //cout<<"\nprev "<<prev<<" char => "<<s[idx];
        
        if((prev.size()>0 and  stoll(prev)> k) || ((s[idx]-'0') > k))  return INT_MAX-100;
        if(idx >= s.size())
        {
            //res = min(sum,res);
            return 0 ;
        }
        
       
        if(dp[idx] !=-1) return dp[idx];
        int take = dfs(s,k,idx+1,sum,prev+ s[idx]);

        string str;
        str.append(1, s[idx]);
        //nottake
        int nottake = 1+ dfs(s,k,idx+1,sum+1, str);

        return  dp[idx] = min(take,nottake);
    
    }
    
    int minimumPartition(string s, int k) {
        
        int n = s.size();
        dp.resize(n+1,-1);
       res = dfs(s,k,0,0,"");
        return res>s.size()? -1 : res+1;
    }
};


// greedy approach for the same java
class Solution {
    public int minimumPartition(String s, int k) {
        long  n =0;
        int res =0;
        for(int i =0 ;i<s.length(); i++)
        {
            n = n*10 + s.charAt(i)-'0';

            if(n>k)
            {
                res++;
                n  = s.charAt(i)-'0';
            }

            if(n>k)
            return -1;

        }

        return res+1;
    }
}
