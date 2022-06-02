//monst optimized approche mentioned below

//  public int jump(int[] nums) {
//         if(nums.length == 1)
//             return 0;
        
//         int temp = 0, max = 0, count = 0;
        
//         for(int i = 0; i < nums.length; i++) {
//             if(i > temp) {
//                 temp = max;
//                 max = 0;
//                 count++;
//             }
            
//             max = Math.max(max, nums[i] + i);
//         }
        
//         return count;
//     }


public class minimumJumps {


    public static int help(int[] arr,int index,int jump,int[] dp)
    {
        if (index >= arr.length-1)
        {
            return 0;
        }


        if (dp[index]!= 10001)
         return dp[index];

        for (int i = 1;i<=arr[index];i++)
        {
            jump+=1;
            dp[index]= Math.min(dp[index],1+help(arr,i+index,jump,dp) );
            jump-=1;

        }

        return dp[index];
    }

    public static int jump(int[] nums) {


        if(nums.length==1) return 0;

        if(nums.length==2) return 1;

        int []dp = new int[nums.length+1];

        for(int i =0;i< dp.length;i++)
            dp[i]= 10001;

       int ans =   help(nums,0,0, dp);


        return ans;
    }
    public static void main(String[] args) {

        int[] arr= {5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4,4,2,0,3,8,5};
        //int[] arr ={1,2,1,1,1};

        System.out.println(jump(arr));
    }
}
