class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        
        unordered_map<char ,int> mp;
        int i =0, res =0;
        for(int j =0 ;j<s.size(); j++)
        {
            mp[s[j]]++;

            if( j-i+1 == k )
            {
               // cout<<"window=> "<<j-i+1 <<" size => "<< mp.size()<<endl;
                if(mp.size() == k) res++;

                if(mp[s[i]] == 1) 
                mp.erase(s[i]);
                else
                mp[s[i]]--; 
                i++;
            }
        }
        //time O(N)
        return res;
    }
};
