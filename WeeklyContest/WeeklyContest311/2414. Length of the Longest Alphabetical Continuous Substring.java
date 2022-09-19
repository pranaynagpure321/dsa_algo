class Solution {
    
    // two pointers easy
    public int longestContinuousSubstring(String s) {
          int n = s.length(), i=0, max =0;
        for (int j =0 ;j< s.length() ;j++)
        {
            char c = s.charAt(j);

            if(j+1 <n &&  c+1 == s.charAt(j+1) )
                continue;
            else
            {
                int win = j -i +1;
                max = Math.max(win ,max);
                i = j+1;
            }
        }

        //time O(n)
        return max;
    }
}
