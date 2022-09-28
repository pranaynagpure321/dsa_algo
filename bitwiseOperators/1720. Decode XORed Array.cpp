class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans ;
        ans.push_back(first);
        
        int ele = first;
        for(int i = 0 ;i< encoded.size() ; ++i)
        {
            ele ^= encoded[i];
            ans.push_back(ele);
        }
        
        return ans;
    }
};
