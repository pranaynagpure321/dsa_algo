#include<iostream>
#include<map>

using namespace std;

int lengthOfLongestSubstring(string s) {

    if(s.length() == 1) return 1;
    int j =0 ,left =0 ;
    int ans = 0 , n = s.length();

    map<char, int> mp;

    while (j < n)
    {
        char c = s[j];
        if(mp.find(c) == mp.end())
        {
            mp.insert({c,1});
            int winsize = j - left +1;
            ans = max(winsize, ans);
        }
        else
        {
            while (mp.find(c) != mp.end())
            {
                char a = s[left++];
                mp.erase(a);
            }
            mp.insert({c,1});
        }
        j++;
    }

    
    
    return ans;

}

int main()
{
    string s = "pwwkew";
    cout<<lengthOfLongestSubstring(s);

}
