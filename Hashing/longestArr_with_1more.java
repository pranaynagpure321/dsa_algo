import java.util.HashMap;

public class LongestSubarrayHavingCountof1sOneMoreThanof0s {


    public static int longest_1more(int[] arr)
    {
        int size=0,sum=0;
        HashMap<Integer,Integer> h1  =new HashMap<>();
        h1.put(0,-1);

        for (int i =0 ;i<arr.length;i++)
        {
            sum += arr[i]==0?-1:1;

            if (sum == 1)
                size = i + 1;

            else if (!h1.containsKey(sum))
            h1.put(sum,i);
            
            if (h1.containsKey(sum-1))
            {
                int winsize = i- h1.get(sum-1);

                if (winsize>size)
                    size=winsize;
            }


        }

        return size;
    }

    public static int longest_equal(int[] arr)
    {
        int size=0 ,sum=0;


        HashMap<Integer,Integer> h1 = new HashMap<>();
        h1.put(0,-1);
       for (int i =0 ;i< arr.length ;i++)
        {
            sum += arr[i]==0?-1:1;

            if (h1.containsKey(sum))
            {
                int winsize = i-h1.get(sum);

                if (winsize>size)
                    size=winsize;
            }

            else
                h1.put(sum,i);
        }

       return size;
    }
    public static void main(String[] args) {

        int[] arr= {0,1,1,0,0,1};
        int[] arr2= {1, 0, 0, 1, 0};
        int[] arr3 = { 0,0,1,1,1,0,0,0};
         //output :5
        // from index 1 to 5


        //System.out.println(longest_equal(arr3));
        System.out.println(longest_1more(arr));

    }
}
