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
