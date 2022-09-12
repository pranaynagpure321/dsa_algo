/*784. Letter Case Permutation
Medium

Share
Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.

Return a list of all possible strings we could create. Return the output in any order.

Example 1:

Input: s = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]
Example 2:

Input: s = "3z4"
Output: ["3z4","3Z4"]*/


#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;



void help(int idx, string s, vector<string>& ans)
{
    if(idx >= s.length())
    {
        ans.push_back(s);
        cout<<s<<endl;
        return;
    }

    char c = s[idx];

    if(s[idx] >= 97  && s[idx] <=122)
    {
        s[idx] =  (char) c -32;
    } else if(c >= 65 && c <= 97)
    {
        s[idx] = (char) c+32;
    }

    //pick
    help(idx+1, s,ans);     //pick means letter is chaged case

    //notpick
    s[idx] =c;                             // not pick case means the letter is kept same 

    if((c >= 97  && c <=122 ) || (c >= 65 && c <= 97))
    help(idx+1, s,ans);

}

vector<string> letterCasePermutation(string s) {

    vector<string > ans;
    help(0,s,ans);

    return ans;

}
int main()
{
    string s = "3z4";
    letterCasePermutation(s);
}
