class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        
    int j =0 , left=0 ,n = s.length() , ans =0;
    map<char,int> mp;

    while ( j < n)
    {
        char c = s[j];
        
        if(mp.count(c) == 0)
        {
            mp.insert({c,1});
        }
        else if(mp.count(c) > 0)
        {
            mp[c] = mp[c] + 1;
        }

        while ( mp.size() > 0)
        {
            if(mp.size() <= k){
                int winsize = j - left + 1;
                ans = max(winsize ,ans);
            }
            if(mp.size() > k)
            {
                int a = s[left++];
                if(mp[a] > 1)
                {
                    mp[a] = mp[a] - 1;
                }
                else
                mp.erase(a);
            }
            else
            break;

        }
        j++;
    }
    
    return ans;
        
    }
};
