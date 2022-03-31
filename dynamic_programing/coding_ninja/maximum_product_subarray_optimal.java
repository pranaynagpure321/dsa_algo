import java.util.ArrayList;

public class Solution { 
	public static int maximumProduct(ArrayList<Integer> arr, int n) {
		
       int ans= arr.get(0);
        int ma=ans,mi=ans;

        for(int i =1;i< n ;i++)
        {
            if(arr.get(i)<0)
            {
                int temp =ma;
                ma=mi;
                mi=temp;
            }

            ma = Math.max(arr.get(i),arr.get(i)*ma);
            mi = Math.min(arr.get(i),arr.get(i)*mi);
            ans = Math.max(ma,ans);
        }

        return ans;
	}
 
}
