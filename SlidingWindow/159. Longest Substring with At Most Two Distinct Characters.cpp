class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        
        unordered_map<int,int> mp;

        int i =0,j=0, mx =0;

        for(j =0 ;j< s.size(); ++j)
        {
            mp[s[j]]++;

            while(mp.size() > 2)
            {
                if(mp[s[i]] == 1)
                mp.erase(s[i]);
                else
                mp[s[i]]--;
                ++i;
            }

            mx = max(mx, j-i+1);
        }
        return mx;
    }
};
