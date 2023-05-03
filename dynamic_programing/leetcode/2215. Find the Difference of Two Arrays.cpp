class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp1, mp2;

        for(int i =0 ;i<nums1.size(); ++i)
        {
            mp1[nums1[i]]++;
        }
        for(int i =0 ;i<nums2.size(); ++i)
        {
            mp2[nums2[i]]++;
        }

        vector<vector<int>> res(2, vector<int>());

        for(int i =0 ;i<nums1.size(); ++i)
        {
            if(!mp2.count(nums1[i]))
            {
                res[0].push_back(nums1[i]);
                mp2[nums1[i]]++;
            }

        }   
        for(int i =0 ;i<nums2.size(); ++i)
        {
            if(!mp1.count(nums2[i]))
            {
                res[1].push_back(nums2[i]);
                mp1[nums2[i]]++;
            }
        } 

        return res;

     }
};
