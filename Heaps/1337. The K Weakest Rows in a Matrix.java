class Solution {
    public int[] kWeakestRows(int[][] mat, int k) {
         int max = -1;
        Comparator<Pair<Integer,Integer>> com = new Comparator<Pair<Integer, Integer>>() {
            @Override
            public int compare(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {

                if(a.getValue() > b.getValue()) return 1;

                else if(a.getValue()< b.getValue()) return -1;

                if(a.getValue() == b.getValue() && a.getKey() < b.getKey() ) return -1;

                return 1;


            }
        };
        PriorityQueue<Pair<Integer,Integer>> pq = new PriorityQueue< >(com);

        int row =0;

        for( int [] sol : mat)
        {
            int count =0;

            for(int i =0 ; i< sol.length ;i++) {
                if (sol[i] == 0)
                    break;
                count++;
            }

            pq.add( new Pair<>(row,count));
            row++;

        }

        int[] ans = new int[k];


        for(int j =0 ;j<k ;j++)
        {
            ans[j] = pq.poll().getKey();
        }

        return ans;
    }
}
