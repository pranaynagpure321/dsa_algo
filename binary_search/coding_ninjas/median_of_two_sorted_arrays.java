import java.lang.reflect.Array;
import java.util.Arrays;

public class Median_of_two_sorted_arrays {

    public static int[] merge(int[] a, int []b)
    {
        int[] ans= new int[a.length+b.length];
        int i=0;
        int j=0;
        int k=0;
        while(i<a.length && j<b.length)
        {
            if( a[i]<=b[j])
            {
                ans[k] = a[i];
                i++;
            }
            else
            {
                ans[k] = b[j];
                j++;
            }
            k++;

        }

        while (i<a.length)
        {
            ans[k] = a[i];
            i++;k++;
        }

        while (j<b.length)
        {
            ans[k] = b[j];
            j++;k++;
        }

        return ans;
    }

    public static double median(int[] a,int[] b)
    {
        double result=0;
        int[] mergedArr= merge(a,b);

        if(mergedArr.length%2!=0)
        {
            return mergedArr[mergedArr.length/2];
        }

        result =mergedArr[mergedArr.length/2]+mergedArr[(mergedArr.length/2) -1];

        return result/2;
    }
    public static void main(String[] args) {

        int[] a ={2,4,6,8};
        int[] b= {1,3,5,7};



        System.out.println(median(a,b));

    }
}
