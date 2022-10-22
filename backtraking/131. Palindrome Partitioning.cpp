class Solution {
public:
    vector<vector<string>> res;
    map<string, bool> mp;
    bool isPalindrome(string s)
    {
        string t = s;
        reverse(t.begin(),t.end());
        if(s==t)                     //store if palindrome
            mp[s] = true;
        else
            mp[s] = false;
        return mp[s];
    }
    void backtrack(int idx, string s ,vector<string>& tmp)
    {
        if (idx >= s.length())
        {
            res.push_back(tmp);
        }

        for (int i = idx; i < s.length(); i++)   // generate every possible palindrome by dfs
        {
            int len = i - idx;
            string t = s.substr(idx, len + 1);
            if(mp.count(s) || isPalindrome(t))
            {
                tmp.push_back(t);
                backtrack(i+1, s, tmp);
                tmp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> tmp;
        backtrack(0,s, tmp);
        return res;
    }
};
