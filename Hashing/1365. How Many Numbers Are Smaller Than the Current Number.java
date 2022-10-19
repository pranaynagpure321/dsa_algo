class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
    
        int[] count = new int[101];
        int[] ans = new int[nums.length];
        
        
        for(int i =0 ;i<nums.length; i++) ///make count of all the numbers
            count[nums[i]]++;
        
        for(int i =1 ;i<101; i++)          // add count of previous numbers as they are smaller than current
            count[i] += count[i-1];
        
        for(int i=0 ; i< nums.length ;i++)     // build ans array
        {
            if(nums[i]==0)
                ans[i] = 0;
            
            else                                // ith index in ans will be (number -1) th index in count number = nums[i]
                ans[i] = count[nums[i]-1];
        }
        
        return ans;
    }
}
