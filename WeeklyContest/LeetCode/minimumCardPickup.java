class Solution {
    public int minimumCardPickup(int[] cards) {
        
         HashMap<Integer,Integer> h1 = new HashMap<>();

        int ans = Integer.MAX_VALUE;

        int start = 0, end =0 ;
        for (int i = 0; i< cards.length ;i++)
        {
            if (!h1.containsKey(cards[i]))
            {
                h1.put(cards[i],i);
            }
            else
            {
                start = h1.get(cards[i]);
                end  = i;
                h1.replace(cards[i],start,i);

                if (end-start<ans)
                    ans = end-start;
            }
        }

        if (ans != Integer.MAX_VALUE)
            return ans+1;

        return -1;
        
    }
}
