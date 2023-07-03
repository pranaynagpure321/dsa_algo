
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        //push all to the vector with <element, list_no>
        vector<pair<int,int>> vec;
        for(int i =0 ;i< nums.size(); ++i)
        {
            for(int j =0 ;j<nums[i].size(); ++j)
            {
                vec.push_back({nums[i][j],i});
            }
        }

        int k = nums.size();
        map<int,int> mp;
        sort(vec.begin(), vec.end());    //sort vector


        int j =0, i =0, mi = 0, mx =INT_MAX;
      
        for(j =0 ;j<vec.size() ; ++j )
        {

            auto &p = vec[j];
            mp[p.second]++;
            while(mp.size() == k)                                  // insert every possible range in pq until mp size is less than k
            {

                if(mx - mi == vec[j].first - vec[i].first ) // logic to compare the pairs 
                {
                    if(  mi>vec[i].first){
                        mx = vec[j].first;
                        mi = vec[i].first;
                    }
                   
                }
                else if(mx - mi > vec[j].first - vec[i].first)   // logic to compare the pairs  mentioned in question
                {
                     mx = vec[j].first;
                        mi = vec[i].first;
                }
               

                if(mp[vec[i].second] == 1)
                mp.erase(vec[i].second);

                else
                mp[vec[i].second]--;

                i++;
            }

        }

        
        vector<int> res = { mi,mx};
        //time O(m*n)
        //space O(m+n)
        return res;
    }
};
