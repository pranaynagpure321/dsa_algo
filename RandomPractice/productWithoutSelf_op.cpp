
  public int[] productExceptSelf(int[] nums) {
        
        
        int[] ans =new int[nums.length];

        ans[0] = nums[0];
        int product =1;

        for(int i =0 ;i< nums.length ;i++)
        {
            product *=nums[i];
            ans [i] = product;

        }

        product =1;

        //ans[A.length-1] = ans[A.length-2];
        for(int i = nums.length-1 ; i>0 ; i--)
        {
            ans[i] = product* ans[i-1];
            product *= nums[i];
        }
        ans[0] = product;
        
        return ans;
        //System.out.println(Arrays.toString(ans));
    }
