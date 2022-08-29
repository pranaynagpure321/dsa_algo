class Solution {
    
    public static int[] topoBFS( int[][] Condition,int k)
    {   ArrayList<Integer> topo = new ArrayList<>();
        int indegree[] = new int[k+1];
        
        //create graph
        ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>>();  
        for(int i = 0;i<= k ; i++) adj.add(new ArrayList<>());
        for( int[] edge : Condition)
        {
            int u = edge[0];
            int v = edge[1];
            adj.get(u).add(v);
        }
        
        //CALCULATE INDEGREE
        for (int i = 1 ;i <= k ; i++)
        {
            for (var m : adj.get(i))
                indegree[m]++;
        }

        Queue<Integer> q = new LinkedList<Integer>();
        for (int i = 1 ;i <= k ; i++)
        {
            if(indegree[i] == 0)
                q.add(i);
        }

        int ind =1;
        
     
        //TOPO ORDER CREATION
        while (!q.isEmpty())
        {
            int node = q.poll();
            topo.add(node); ind++;
           // System.out.print(node+" ");

            for (var neigh : adj.get(node))
            {
                indegree[neigh]--;

                if(indegree[neigh]==0) q.add(neigh);
            }

        }

        int topo2[] = new int[topo.size()];
        int i =0;
        for (int a : topo)
        {
            topo2[i++] = a;
        }
        return topo2;   //return topo order
    }
    public int[][] buildMatrix(int k, int[][] rowConditions, int[][] colConditions) {
       
        int row_order [] = topoBFS(rowConditions,k);   //TAKE ROW TOPO ORDER
        int col_order[] = topoBFS(colConditions,k);    //TAKE COL ODER TOPO


        if(row_order.length< k || col_order.length <k ) return new int[0][0];   //RETURN IS CYCLE IN GRAPH

        int ans[][] = new   int[k][k];
        HashMap<Integer,Integer> mp = new HashMap<>();


        for (int i =0 ;i< k ; i++)
        {
            mp.put(col_order[i], i);        // PUT 1 : 0 , 2:3 , 3:2 COL ODER AND RESPECTIVE COLMUNS
        }

        for (int i  =0 ;i< k ;i++)
        {
            int column_position = mp.get(row_order[i]);                          // GET VALUES OF MAP BY ROW ORDER
            ans[i][column_position] = row_order[i];                               //PUT VALUES IN ANS ARRAY
        }

        System.out.println(Arrays.deepToString(ans));

        return ans;

    }
}
