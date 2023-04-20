class Solution {
public:
    int minimumKeypresses(string s) {
    
      unordered_map<char, int> mp;
      int res = 0;
      for(char ch : s)
      {
        mp[ch]++;
      }
      vector<pair<int,char>> v;
      for(auto& p : mp)
      {
        v.push_back({p.second, p.first});
      }
      sort(v.begin(),v.end());
      int j =1, stoke = 1;
      for(int i = v.size()-1 ; i>=0 ; --i)
      {
          res += stoke*v[i].first;
          j++;

          if(j>= 10)
          {
            j = 1 , stoke++;
          }
      }
      return res;
    }
};
