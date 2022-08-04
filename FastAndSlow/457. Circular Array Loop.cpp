/*Medium

410

377

Add to List

Share
You are playing a game involving a circular array of non-zero integers nums. Each nums[i] denotes the number of indices forward/backward you must move if you are located at index i:

If nums[i] is positive, move nums[i] steps forward, and
If nums[i] is negative, move nums[i] steps backward.
Since the array is circular, you may assume that moving forward from the last element puts you on the first element, and moving backwards from the first element puts you on the last element.

A cycle in the array consists of a sequence of indices seq of length k where:

Following the movement rules above results in the repeating index sequence seq[0] -> seq[1] -> ... -> seq[k - 1] -> seq[0] -> ...
Every nums[seq[j]] is either all positive or all negative.
k > 1
Return true if there is a cycle in nums, or false otherwise.

 

Example 1:

Input: nums = [2,-1,1,2,2]
Output: true
Explanation:
There is a cycle from index 0 -> 2 -> 3 -> 0 -> ...
The cycle's length is 3. */


class Solution {
public:
    
    int getNext(int i, vector<int>& nums)
    {
         int t = i + nums[i];
         t = t>= nums.size() ? t%nums.size() : t;
         return t;       
    }
    
    int getBack(int i, vector<int>& nums)
    {
         int t = i + nums[i];
         if(t<0)
         t =  abs(t) >= nums.size() ? t%nums.size() : t + nums.size();
         return t;       
    }
    bool circularArrayLoop(vector<int>& nums) {
        
        int n = nums.size();
        
        for(int i =0 ; i < nums.size() ; i++)
        {
            int tortoise = i;
            int hare = i;
            int count =0;
        
            while(nums[i] > 0 and count < n)
            {
                
                tortoise = getNext(tortoise , nums);
                
                hare  = getNext(hare, nums);
                
                int  TempHare  = getNext(hare, nums);
             
                if ( nums[tortoise] < 0 or nums[hare] < 0   or  (hare == TempHare)  or nums[TempHare] < 0)
                {
                     count =0 ; break;
                }
                
                hare = TempHare;
                
                if(tortoise == hare) { count++ ; break; }
                
                count++;
            }
            
            
            while(nums[i] < 0 and count < n )
            {
                tortoise = getBack(tortoise , nums);
                
                hare  = getBack(hare, nums);
                
                int  TempHare  = getBack(hare, nums);
                
                if(  nums[tortoise] > 0 or nums[hare]> 0    or  (hare == TempHare) or nums[TempHare] > 0 )
                {
                    
                    count =0 ; break;
                }
                
                 hare = TempHare;
                
                if(tortoise == hare) { count++ ; break; }
                
                count++;
            }
            
            
           if(tortoise == hare and count <= n and count > 1) return true;
        }
        
        return false;
        
    }
};
