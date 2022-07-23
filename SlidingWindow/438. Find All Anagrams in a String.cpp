class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
         int char_counts[26] , left =0;
    int s_char_counts[26];
    vector<int> ans;

    memset(char_counts , 0 , sizeof(char_counts));

    for(int i =0 ;i< p.length() ; i++ )
    {
       char_counts[p[i] - 'a']++;
    }

    for(int j = 0 ; j < s.length() ; j++)
    {
        int c = s[j] - 'a';

        if(char_counts[c] > 0)
        {
            left = j;
            memset(s_char_counts , 0 , sizeof(s_char_counts));
            int  count=0;
            while ( c >=0 && char_counts[c] > 0)
            {
                s_char_counts[c]++;
                if(s_char_counts[c] > char_counts[c]) break;

                count++;
                c = s[++left]- 'a';
            }

            if(count == p.length())
            {  ans.push_back(j);}  

        } 
    }

    return ans;
    }
};
