class Solution {
public:

    int expandCenter(int L, int R, string s)
    {
        while(L>=0  and R < s.size() and s[L] == s[R])
        {
            L--; R++;
        }
        return R - L - 1;
    }
    string longestPalindrome(string s) {

        if(s.length()<1) return "";
        int start =0 , end =0;
        int len1 =0, len2 =0;
        for(int i =0 ;i<s.size();i++)
        {
            len1 = expandCenter(i,i,s);
            len2 = expandCenter(i,i+1,s);
            int t = max(len1,len2);
            if(t> end-start)
            {
                start = i - ((t-1)/2);
                end = i + t/2;                
            }
        }
        int cnt = end - start +1;
        return s.substr(start,cnt);
        
    }
};
