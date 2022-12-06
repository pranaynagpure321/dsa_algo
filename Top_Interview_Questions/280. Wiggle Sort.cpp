class Solution {
public:
    void wiggleSort(vector<int>& nums) {


       for(int i =0 ;i< nums.size()-1; i++)
       {
           if(i%2 ==0 )  // if even and current if greter than next then swap
           {    
               if(nums[i]>nums[i+1])
               swap(nums[i],nums[i+1]);
           }
           else  // in odd if next is greater then swap
           {
               if(nums[i]<nums[i+1])
               swap(nums[i],nums[i+1]);
           }
         
         //time O(N)
         //space O(1)
       } 

    //  sort(nums.begin(), nums.end());
    // for (int i = 1; i < nums.size() - 1; i += 2) {
    //     swap( nums[i], nums[i + 1]);
    // };

       
    }
};
