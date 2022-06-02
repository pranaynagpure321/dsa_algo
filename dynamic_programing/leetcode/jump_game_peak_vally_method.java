class Solution {
    public boolean canJump(int[] nums) {
        
       if(jump(nums)==0)
           return false;
        
        return true;
        
    }
    
    
    public int jump(int[] nums)
    {
        int reachable=0; // we will update the reachable as we move forward
        int n=nums.length;
        for(int i=0;i<n;++i){
        if(reachable<i){
            return 0;
        }
            reachable=Math.max(reachable,i+nums[i]);
        }
        return 1;
    }

    
    
}
