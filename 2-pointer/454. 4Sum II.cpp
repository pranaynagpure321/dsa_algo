class Solution {
public:
     int fourSumCount(vector<int>& n1, vector<int>& n2, vector<int>& n3, vector<int>& n4) {
        
        int size = n1.size();
        unordered_map<int, int> mp;
         
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                mp[n1[i] + n2[j]]++;
            }
        }

        int res = 0;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                int antisum = -1 * (n3[i] + n4[j]);
                if (mp.count(antisum))
                    res += mp[antisum];
            }
        }
        
        //time O(n2)
        return res;
        
        
    }
};
