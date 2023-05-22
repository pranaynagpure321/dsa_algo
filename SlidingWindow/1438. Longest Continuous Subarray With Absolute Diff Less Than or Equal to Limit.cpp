class Solution {
public:

// use multiset to maintain the sorted order and check the first and last element diff to increase or decrese the window
    int longestSubarray(vector<int>& nums, int limit) {
        
        multiset<int> set;
        int i=0 ,j=0;
        for( j =0 ;j< nums.size(); j++)
        {
            set.insert(nums[j]);

            if(*set.rbegin() - *set.begin() > limit)
            set.erase(set.find(nums[i++]));
        }

        return j - i;
    }
};


// java solution to same problem 

class Solution {
    public int longestSubarray(int[] nums, int limit) {
        
        int i =0 ,j;

        TreeMap<Integer, Integer> mp= new TreeMap<>();
        
        for(j = 0 ; j< nums.length; j++)
        {
            mp.put(nums[j], 1+ mp.getOrDefault(nums[j],0));

            if(mp.lastEntry().getKey() - mp.firstEntry().getKey() > limit){
                
                mp.put(nums[i], mp.get(nums[i]) -1);

                if(mp.get(nums[i]) == 0)
                mp.remove(nums[i]);

                i++;
            }
        }
        return j - i;
    }
}


// solution t based on deque
class Solution {
public:

// use multiset to maintain the sorted order and check the first and last element diff to increase or decrese the window
    // int longestSubarray(vector<int>& nums, int limit) {
        
    //     multiset<int> set;
    //     int i=0 ,j=0;
    //     for( j =0 ;j< nums.size(); j++)
    //     {
    //         set.insert(nums[j]);

    //         if(*set.rbegin() - *set.begin() > limit)
    //         set.erase(set.find(nums[i++]));
    //     }

    //     return j - i;
    // }

    int longestSubarray(vector<int>& nums, int limit) {
    
    deque<int> maxQ, minQ;

    int i =0 , j,res =0 ;

        for(j =0 ; j<nums.size() ; ++j)
        {
            while(!maxQ.empty() and maxQ.back() < nums[j] )
            {
                maxQ.pop_back();
            }
            maxQ.push_back(nums[j]);

            while(!minQ.empty() and minQ.back() > nums[j])
            {
                minQ.pop_back();
            }

            minQ.push_back(nums[j]);

            while(maxQ.front() - minQ.front() > limit)
            {
                if(maxQ.front() == nums[i]) maxQ.pop_front();
                if(minQ.front() == nums[i]) minQ.pop_front();
                i++;
            }

            res = max(res, j - i+1);
        }

        return res;
    }
};
