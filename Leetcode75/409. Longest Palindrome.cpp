class Solution {
public:
    int longestPalindrome(string s) {
        
        vector<int> char_counts(58);
        
        for(int i =0 ;i<s.length() ; i++)
        {
            char_counts[s[i] - 'A']++;
        }
        
        int ans =0;
        
        
        for (int v: char_counts) {
            
            
            ans += v / 2 * 2;
            if (ans % 2 == 0 && v % 2 == 1)
                ans++;
        }
        
        return ans ;
        
    }
};
