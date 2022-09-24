/*1461. Check If a String Contains All Binary Codes of Size K
Medium

1928

90

Add to List

Share
Given a binary string s and an integer k, return true if every binary code of length k is a substring of s. Otherwise, return false.

 

Example 1:

Input: s = "00110110", k = 2
Output: true
Explanation: The binary codes of length 2 are "00", "01", "10" and "11". They can be all found as substrings at indices 0, 1, 3 and 2 respectively.
Example 2:

Input: s = "0110", k = 1
Output: true
Explanation: The binary codes of length 1 are "0" and "1", it is clear that both exist as a substring. 
Example 3:

Input: s = "0110", k = 2
Output: false
Explanation: The binary code "00" is of length 2 and does not exist in the array.*/

class Solution {
public:
    bool hasAllCodes(string s, int k) {
         map<int ,int> mp;
        int n = s.length();

        for (int i = 0; i <n-k+1; i++) {

            if(i+k <=n )
            {
                string tmp = s.substr(i,k);
                int t = stoi(tmp, nullptr,2);
                mp[t]=i;
                
                //cout<< "binary=> " << tmp << " location => " << i << " dec=> "<<t<<endl;
            }

        }
        
        int size = round(pow(2,k));
        
        for (int i = 0; i < size; i++) {
            
            if(mp.find(i)== mp.end()) return false;
        }
        
        
        // time O(n*k)
        return true;
    }
};

//second solution
class Solution {
public:
    bool hasAllCodes(string s, int k) {
         unordered_set<string > mp;
        int n = s.length();
        
        if(k> n) return false;

        for (int i = 0; i <= n-k; i++) {
            string tmp = s.substr(i,k); 
            mp.insert(tmp);
        }
        
        int size = round(pow(2,k));
        
        // time O(n*k)
        return size == mp.size();
    }
};

// 3rd approach
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        //rolling hash
        unordered_set<string > mp;
        int n = s.length();
        
        if(k> n) return false;
        
        string tmp =s.substr(0,k);
        mp.insert(tmp);
        
        for (int i = k-1; i <n; i++) {
            
            tmp.erase(0,1);
            tmp += s[i];
            mp.insert(tmp);
        }
        
        int size = 1<<k;
        
        // time O(n)
        return size == mp.size();
    }
};
