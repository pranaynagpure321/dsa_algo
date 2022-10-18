class Solution {
     static ArrayList<ArrayList<Integer>> getGraph(int n , int[][] edges)
    {
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>(n+1);

        for (int i =0 ;i<=n ;i++)
            adj.add(new ArrayList<>());

        for(var edge : edges)
        {
            int u = edge[0] , v = edge[1];
            adj.get(u).add(v);
        }

        return adj;
    }
    public int minimumSemesters(int n, int[][] relations) {
      ArrayList<ArrayList<Integer>> adj =  getGraph(n,relations);
        int[] indeg = new int[n+1];
        Queue<Integer> q = new LinkedList<>();

         for (int i =1 ;i<=n ;i++)
         {
             for (int a : adj.get(i))
             {
                 indeg[a]++;
             }
         }

        for (int i = 1; i < n+1; i++)
            if(indeg[i] ==0)
                q.add(i);


        int cnt =0;

       
        while (!q.isEmpty())
        {
            cnt++;
            int size = q.size();
            //interate as bfs
            for(int i = 0 ;i<size ;i++) {
                int node = q.poll();

              
                for (var a : adj.get(node)) {
                    indeg[a]--;

                    if (indeg[a] == 0) {
                        q.add(a);
                    }
                }
            }
           
        }

       for (int in : indeg) if(in>0) return -1;

        //time O(N+E) E is for iterate relations once
        return cnt;
    }
}
