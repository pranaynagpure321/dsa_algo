class Solution {
public:
    int maxProduct(vector<string>& words) {
        
         vector<vector<int>> maps;

        for (int i = 0; i < words.size(); ++i) {
            string s = words[i];
            vector<int> v(26);
            for (int j = 0; j < s.size(); ++j) {
                char c = s[j];
                v[c-'a']++;
            }

            maps.push_back(v);                     // creating char counts array 
        }

        int mx = 0;
        for (int i = 0; i < maps.size(); ++i) {

            auto u = maps[i];

            for (int j = i+1; j < maps.size(); ++j) {
                auto v = maps[j];
                int m = 0, n =0 ;
                bool isGood = true;

                for (int k = 0; k < 26; ++k) {          // comparing each char_couts array

                    if(u[k]>0 and v[k]>0)
                    {
                        isGood = false; break;
                    }
                }

                int cur = words[i].size()*words[j].size();
                if(isGood)
                    mx = max(cur, mx);

            }
        }
        //time n^2 * 26
        return mx;
    }
};
