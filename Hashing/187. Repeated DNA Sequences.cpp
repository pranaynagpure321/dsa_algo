
/*The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.

For example, "ACGAATTCCG" is a DNA sequence.
When studying DNA, it is useful to identify repeated sequences within the DNA.

Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in any order.

 

Example 1:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]*/



class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        unordered_map<string, int> mp;
        vector<string> ans;
        
        if(s.length() < 10) return ans;
        int len =10;
        
        for(int i =0 ; i <= s.length()-10 ; i++ )
        {
            string temp = s.substr(i,10);
            
            if(mp.find(temp) != mp.end())
            {
                mp[temp]++;
                
               if( mp[temp] > 1 and mp[temp]  < 3) ans.push_back(temp);
            }
            else
                mp.insert({temp,1});
        }
        
        return ans;
        
    }
};
