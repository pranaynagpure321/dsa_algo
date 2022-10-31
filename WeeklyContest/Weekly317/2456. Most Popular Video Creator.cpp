class Solution {
public:
      map<string, pair<int, string>> findmax(vector<string>& creators,vector<string>& ids, vector<int>& views)
    {
        
        map<string, pair<int, string>> mp;

        for (int i = 0; i < ids.size(); ++i)
        {
            int cur_cnt = views[i];

            if (mp.count(creators[i]))
            {
                if (cur_cnt > mp[creators[i]].first || (cur_cnt == mp[creators[i]].first and ids[i] <= mp[creators[i]].second))
                {
                    mp[creators[i]].first = cur_cnt;
                    mp[creators[i]].second = ids[i];
                }
                
            }
            else
            {
                mp[creators[i]].first = cur_cnt;
                mp[creators[i]].second = ids[i];
            }
        }

        return mp;
    }
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
          //find highest popularity

        //find highest popularity

         map<string, int> mp;
        int mod = 1e9 + 7;
        int n = creators.size();
        for (int i = 0; i < n; ++i)
        {
            mp[creators[i]] += views[i]%mod;
            mp[creators[i]] = mp[creators[i]] % mod;
        }

        vector<pair<int, string>> vec;

        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            vec.push_back({ it->second, it->first });
        }

        sort(vec.begin(), vec.end() );

        vector<vector<string>> ans ;

        int mx = 0;
        int j = 1;
        int k = 0;
        for (int j = vec.size()-1; j >=0 ; j--)
        {
            if (mx <= vec[j].first)
            {
                ans.push_back({});
                ans[k++].push_back(vec[j].second);
                mx = vec[j].first;
            }
            else break;
        }

         
        auto max_popu = findmax(creators, ids, views);
        for (auto &v : ans)
        {
           
            string name = v[0];
            v.push_back(max_popu[name].second);
        }
        //too complex
        return ans;
    }
};
