class Solution {
public:

    //my attempt 
    /* intuition
        consrtuct temporary word by letter by letter then if we fouund substring in map then call backtracking function to check if its composite word it must bbe formed with at least 2 word to be composite.
    */

    bool is_composite(string &s,map<string,bool> &mp , int k , int idx )
    {
        if(idx >= s.size() and k>1) return true ;
        if(idx >= s.size() ) return false;
        string tmp ="";
        for(int i = idx ;i < s.size(); i++)
        {
            tmp += s[i];
            if(tmp != s and mp.count(tmp))
            {
                if(  is_composite(s,mp, k+1, i+1))
                return true;
            }
        }
        return false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {

        vector<string> res;
        map<string,bool> mp;
        for(string s : words)
        mp[s] = true;
        bool iscomposite = false;
        for(string s : words)
        {
            string word = "";
            for(char ch : s)
            {
                word += ch;
                if(mp.count(word) and is_composite(s,mp,0,0))
                {
                    mp.erase(s);
                    res.push_back(s); break;
                }
            }
        }
        return res;
    }
};
