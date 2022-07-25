public class ArrayLeftRight {


    public  static  boolean  help(int[] arr, int i, int count , int curSum ,int sum, String picked)
    {
        if (count == arr.length/2)
        {
            if (curSum*2 == sum)
                return true;
            return false;
        }
        if(i >= arr.length)
        {
            return false;
        }

        boolean pick = help(arr,i+1,count+1 ,curSum+arr[i],sum , picked+","+(i+1));

        if(pick) return  true;

        boolean notpick = help(arr,i+1,count, curSum,sum ,picked);

        if(notpick) return true;

        return false;
    }

     static   boolean arrayLeftRight(int[] arr)
    {
        int sum =0 ;

        for(int c : arr)
            sum+=c;

        if(sum%2 != 0) return  false;

        boolean ans = help(arr,0,0, 0, sum,"");

        return  ans;
    }

    public static void main(String[] args) {


        //int[] arr= { 1,5,5,5,6,8};
        int[] arr = {5,7,7,7,7,5,5,5};//5,7 5,7  = 5,7,5,7 both left and right array must be equal
        System.out.println(arrayLeftRight(arr));

    }
}
