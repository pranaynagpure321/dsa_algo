class Solution {
public:
      
    string oddString(vector<string>& words) {
        for (int j = 0; j + 1 < words[0].size(); ++j)
        {
            unordered_map<int, vector<int>> mp;
            for (int i = 0; i < words.size(); ++i)
            {
                mp[words[i][j + 1] - words[i][j]].push_back(i);
            }


            if (mp.size() == 2)
            {
                for (auto& p : mp)
                {
                    auto &vec = p.second;
                    if (vec.size() == 1)
                        return words[vec[0]];
                }
            }
        }
        return  words[0];

    }
};
