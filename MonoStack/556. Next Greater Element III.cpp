class Solution {
public:
    int ans = -1;
    
    // brute force
    void permute(string &s, int idx, int& n )
    {
        if (idx == s.length()) {

            long a = stol(s);

            if (a <= INT_MAX and a >n) { 
                int tmp =(int)a;
                ans = ans>0 ? min(ans,tmp): tmp;
            }
        }
            

        for (int i = idx; i < s.length(); i++)
        {
            swap(s[idx], s[i]);
             permute(s, idx + 1,n);
            swap(s[idx], s[i]);
        }

        
    }
    int nextGreaterElement(int n) {
        string s = to_string(n); 
       
        //permute(s,0,n);
        
        //optimized
       int i = s.length()-2;
       while ( i>=0 && s[i]   >=  s[i + 1]  )i--;             // find first decresing element
       
       if (i < 0) return -1;

       int j = s.length() - 1;

       while (j >= 0 and s[j] <= s[i])j--;                 // find the smallest greater element which we can use to swap
      
       swap(s[i], s[j]);

       reverse(s.begin() + i + 1, s.end());                // reverse the string from i+1 th index
        
       if (stol(s) > INT_MAX) return -1;
        return  stoi(s);
    }
};
