import java.lang.reflect.Array;
import java.util.Arrays;

public class Epifi {


    static  int houseRobber(int[] arr,int start,int[] dp )
    {

        if (start>=arr.length )
        {
           return 0;
        }

        if (dp[start]!= -1)
            return dp[start];

        int notPick=  houseRobber(arr,start+1,dp);
        int pick = arr[start] + houseRobber(arr, start+2,dp );
        return dp[start] = Math.max(notPick,pick);

    }

    static int[] split(int[] arr ,int i ,int j)
    {
        int[] temp = new int[j-i+1];
        for (int k =i;k< j;k++)
        {
            temp[k]=arr[k];
        }

        return temp;
    }


    public static void main(String[] args) {


        int[] arr = { 2,3,2};
        int[] newarr = split(arr,1,arr.length);
        int[] secarr = split(arr,0,arr.length-1);
        int[] dp = new int[newarr.length+1];
        int[] dp2 = new int[secarr.length+1];
        Arrays.fill(dp,-1);
        Arrays.fill(dp2,-1);

        int ans=  Math.max(houseRobber(newarr,0,dp ),houseRobber(secarr,0,dp2 )) ;
        System.out.println(ans);

    }
}
