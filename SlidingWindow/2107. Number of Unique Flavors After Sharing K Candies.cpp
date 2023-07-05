class Solution {
public:
    int shareCandies(vector<int>& candies, int k) {

        int   j=0;
        unordered_map<int,int> mp;

        for(int i = k; i< candies.size(); ++i)
        mp[candies[i]]++;

        int ans  = mp.size();

        for(j =k ;j< candies.size(); ++j)
        {
            if(--mp[candies[j]] == 0) mp.erase(candies[j]);
            ++mp[candies[j-k]];

            ans = max(ans , (int) mp.size());

        }

    return ans;

      
    }
};
