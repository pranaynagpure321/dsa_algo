#include<iostream>
#include<map>
#include <bits/stdc++.h>

using namespace std;


int characterReplacement(string s, int k) {
    
    int  left =0 , n = s.length(), ans =0 ,  maxcount =0 , j =0;

    int char_counts[26];

    memset(char_counts, 0, sizeof(char_counts));

    while (j < n)
    {
        
        char  c = s[j] ;
        char_counts[c - 'A']++;
        int curcount =  char_counts[c - 'A'] ;
        maxcount = max(curcount , maxcount);

        while (j - left - maxcount + 1 > k )
        {
            char a = s[left++];
            char_counts[a - 'A']--;

        }
         
        ans = max(ans, j-left+1);
        j++;
    }
    
    
    return ans;

}


int main()
{
    string s = "AABABBA"; int  k = 1;

    // second replacing character need to find

    cout<<characterReplacement(s,k);
}
