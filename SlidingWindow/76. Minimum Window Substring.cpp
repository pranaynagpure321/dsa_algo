class Solution {
public:
   

    string minWindow(string s, string t) {
        
        if(t.length() > s.length()) return ""; 
        if(t.length() == s.length() && s==t) return t;
        int char_counts[58] , s_char_counts[58];
        int left = 0 ,minSize = s.length() + 1 ;
        string ans="";

        memset(char_counts, 0 ,sizeof(char_counts));
        memset(s_char_counts, 0 ,sizeof(s_char_counts));

          int count = 0 , needcount = 0;
        for(int i =0 ;i<t.length() ; i++)
        {
            if(char_counts[t[i] - 'A'] == 0) needcount++;
            char_counts[t[i] - 'A']++;
        }



        for(int j =0 ;j <s.length() ; j++)
        {
            int c = s[j] - 'A';

            s_char_counts[c]++;

            if(char_counts[c] > 0 and  char_counts[c] == s_char_counts[c]) count++;

            while (count == needcount && left<=j)
            {
                int winsize = j -left + 1;
                if(winsize < minSize)
                {
                    minSize = winsize;
                    ans = s.substr(left,minSize);
                }
                int lc = s[left] - 'A';
                s_char_counts[lc]--;
                if(char_counts[lc] > 0  and s_char_counts[lc] < char_counts[lc]) count--;

                left++;
            }

        }

        return ans;
    }
};




int main()
{
    //string  s = "bdab", t = "ab";
    //string s = "ADOBECODEBANC", t = "ABC";
    //string s = "cabwefgewcwaefgcf", t="cae";
    //string s = "a" , t="a";
    //string s = "ab", t = "b";
    //string s= "aa", t="aa";
    //string s="bbaa",t="aba";
    string s ="cgklivwehljxrdzpfdqsapogwvjtvbzahjnsejwnuhmomlfsrvmrnczjzjevkdvroiluthhpqtffhlzyglrvorgnalk" , t="mqfff" ;
    
    cout<<minWindow_4(s,t);
}
