
public class GoldemanPrep {

    public static int pivotIndex2(int[] nums) {

        int sum = 0;

        for (int i =0;i< nums.length;i++)
            sum+=nums[i];
        int left=0,right=sum;

        for (int j =0 ;j<nums.length;j++)
        {
            if (j==0)
            {
                right=right-nums[j];
                if (right==left)
                    return j;
            }

            else
            {
                left += nums[j-1];
                right = sum-nums[j]-left;
                if (right==left)
                    return j;
            }
        }

        return -1;
    }
  
   
    public int pivotIndex(int[] nums) {
        int sum = 0, leftsum = 0;
        for (int x: nums) sum += x;
        for (int i = 0; i < nums.length; ++i) {
            if (leftsum == sum - leftsum - nums[i]) return i;
            leftsum += nums[i];
        }
        return -1;
    }


    public static void main(String[] args) {

        int[] arr = {1,2,3};

        System.out.println(pivotIndex2(arr));

    }
}
