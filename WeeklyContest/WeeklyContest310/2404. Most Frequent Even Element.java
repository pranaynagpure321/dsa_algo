import java.util.Hashtable;
class Solution {
    public int mostFrequentEven(int[] nums) {
        Hashtable<Integer, Integer> h1 = new Hashtable<>();
        int maxf =0, ans =-1 ;
        for(int i : nums)
        {
            if(i%2 ==0){
                h1.put(i, h1.getOrDefault(i, 0) + 1);

                if (h1.get(i) > maxf) {
                    maxf = h1.get(i);
                    ans = i;
                }
                else if(h1.get(i) == maxf)
                {
                    ans = Math.min(i,ans);
                }
            }
        }

        return ans;
    }
}
