
// using priority queue

class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) { 
        map<int,int> mp;
        
        int mf =0;
        
        for(int i =0 ;i<nums.size() ; i++)
        {
            mp[nums[i]]++;    
            
            mf =max(mf,mp[nums[i]]);
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>> > pq;
        
        for(auto &p : mp)
        {
            pq.push(make_pair(p.second, p.first));
            while(pq.size()> k)
            {
                pq.pop();
            }
        }
        
        vector<int> m;
        
        while(pq.size())
        {
            m.push_back(pq.top().second);
            pq.pop();
        }
      
      //time nlogk
      //space(n)
        
        return m;
    }
};





//using bucketsort

class Solution {
public:
    
  
    vector<int> topKFrequent(vector<int>& nums, int k) { 
        
        if(k == nums.size() ) return nums;
        
        map<int,int> mp;
        
        for(int num : nums)
            mp[num]++;                                  // take all the frequencey
        
        
        //bucket sort 
        
        vector<vector<int> > buckets (nums.size()+1,vector<int>());                   //create buckets
        
        for(auto &p : mp )
        {
            buckets[p.second].push_back(p.first);
        }

        
        vector<int> falttnedlist;                       // this list will contain only elements with higher frequency first
        
        for( int i = buckets.size()-1 ; i>= 0 ; i--)                  // traverse bucket reverse to get maximum value first
        {
            for(int vl : buckets[i])
            falttnedlist.push_back(vl);
        }
        
        vector<int> ans;                                 //final ans vector
        
        for(int i =0 ;i<k ; i++)
        {
            ans.push_back(falttnedlist[i]);
        }
        
        
        //time O(n)
        //spaceO(n)
        
        return ans;
    }
};
