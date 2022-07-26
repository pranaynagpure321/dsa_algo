#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

//time taken 6hrs


bool checkFirst_2(string ans, vector<string>& words)
{
    unordered_map<string , int> mp;

    for(int i =0 ;i< words.size() ;i++)
    {
        mp[words[i]]++;
    }

    int len = words[0].length();
    unordered_map<string , int> mp2;

    for(int j =0 ;j< ans.length() ; j+=len)
    {
        string temp = ans.substr(j,len);
        mp2[temp]++;
    }

    if(mp == mp2)
    return true;

    return false;
}


vector<int> findSubstring(string s, vector<string>& words) {

    int char_counts[26];

    memset(char_counts, 0, sizeof(char_counts));


    vector<int> result;

    int needcount = 0 , requireL =0 ;
    
    requireL += words[0].length()*words.size();

    for( int i =0 ; i< words.size() ; i++)
    {
        for(char c : words[i])
        {
            int index = c - 'a';
            if(char_counts[index] == 0) needcount++;

            char_counts[index]++;
        }
    }
    
    sort(words.begin(), words.end());
    int left =0 , have =0  ;
    int s_char_counts[26];
    memset(s_char_counts, 0, sizeof(s_char_counts));
   
    for(int j = 0 ; j < s.length() ; j++ )
    {
       int c = s[j] - 'a';

       s_char_counts[c]++;

       if(char_counts[c] > 0 && char_counts[c] == s_char_counts[c]) have++;

       while (have == needcount)
       {
            int winsize = j - left + 1;
            string ans =  s.substr(left, winsize);
           if(ans.length() == requireL   and checkFirst_2(ans,words) )
           { 
               result.push_back(left);
               
                cout<<ans<<endl;
           }

            int lc = s[left]- 'a';

            s_char_counts[lc]--;

            if(char_counts[lc] > 0 && s_char_counts[lc] < char_counts[lc]) have--;

            left++;
       }
       
    } 
    return result;

}


 

int main()
{
    //string   s = "barfoothefoobarman"; vector<string> words = {"foo","bar"};
    //{0,9}

    //string   s = "wordgoodgoodgoodbestword"; vector<string> words = {"word","good","best","word"};
    //{}
    
    //string   s = "barfoofoobarthefoobarman"; vector<string> words = {"bar","foo","the"};
    //{6,9,12}
    
    //string   s = "abababab"; vector<string> words = {"ab","ab","ab"};
    //{0,2}

    //string   s = "abababab"; vector<string> words = {"ab","ba"};
    //ans {}

   //string s = "ababababab"; vector<string> words =  {"ababa","babab"};
   //ans {0}

   string   s = "ababaab"; vector<string> words = {"ab","ba","ba"};
   //ans{1}

    vector<int> v= findSubstring(s,words);

    for(int a: v )
    cout<<a;
}
