class Solution {
public:

    int longestSubstring(string s, int k) {
        map<char,int> mp;
        for(char c: s)
        mp[c]++;
        int TotaluniqueChars = mp.size();
        int res =0;
        for(int currchar =1 ; currchar<= TotaluniqueChars ; currchar++ )
        {
            int j =0 ,i=0;
            int unique= 0;
            map<char,int> tmpMap;
            int atLeastKCount =0;

            while(j<s.length())
            {
                if(unique <= currchar)
                {
                    char ch = s[j++];
                    tmpMap[ch]++;
                    if(tmpMap[ch]==k) atLeastKCount++;
                }
                else{
                    
                    char ch = s[i++];
                    if(tmpMap[ch] == k) atLeastKCount--;
                    if(tmpMap[ch]==1)
                    tmpMap.erase(ch);
                    else 
                    tmpMap[ch]--;
                }

                 unique = tmpMap.size();
                if(unique == currchar and unique == atLeastKCount)
                res = max(j-i, res);
            }

        }
        //time O(26*N) => O(N)
        return res;
    }
};
