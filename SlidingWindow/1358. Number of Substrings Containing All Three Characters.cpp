class Solution {
public:
    int numberOfSubstrings(string s) {
        map<char ,int> mp;
        int i =0 , j, res =0 , n =s.size();
        for( j =0 ; j <s.size() ; ++j   )
        {
            mp[s[j]]++;

            while(mp.size()  == 3){ 
                mp[s[i]]--;
                res += n - j  ;
                if(mp[s[i]] ==0 )
                mp.erase(s[i]);

                i++;
            }
        }
        return res;
    }
};
