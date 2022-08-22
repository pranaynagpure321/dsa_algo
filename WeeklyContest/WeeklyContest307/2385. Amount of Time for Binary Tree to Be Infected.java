/*2385. Amount of Time for Binary Tree to Be Infected
User Accepted:4322
User Tried:5498
Total Accepted:4457
Total Submissions:8725
Difficulty:Medium
You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.

Each minute, a node becomes infected if:

The node is currently uninfected.
The node is adjacent to an infected node.
Return the number of minutes needed for the entire tree to be infected.

 

Example 1:


Input: root = [1,5,3,null,4,10,6,9,2], start = 3
Output: 4
Explanation: The following nodes are infected during:
- Minute 0: Node 3
- Minute 1: Nodes 1, 10 and 6
- Minute 2: Node 5
- Minute 3: Node 4
- Minute 4: Nodes 9 and 2
It takes 4 minutes for the whole tree to be infected so we return 4.

Solution explanation first build the graph and the dfs on graph to find maximum distance;
*/


import java.util.*;

public class weekly307 {
   static class TreeNode {
      int val;
      TreeNode left;
      TreeNode right;
      TreeNode() {}
      TreeNode(int val) { this.val = val; }
      TreeNode(int val, TreeNode left, TreeNode right) {
          this.val = val;
          this.left = left;
          this.right = right;
      }
  }
    public static String largestPalindromic(String num) {

        int[] cnt = new int[11];
        for( var c : num.toCharArray() ) cnt[c- '0']++;

        String lp="",rp="", ans= "";

        for ( int i = 9 ;i>=0 ; i--)
        {

            if(lp.length() == 0  && i ==0) continue;
            if(cnt[i] > 1  )
            {
                while(cnt[i] > 1 )
                {
                    lp +=   i;
                    rp +=   i;
                    cnt[i] -=2;

                }
            }
        }

        for(int i = 9 ; i>= 0 ; i--)
        {
            if(cnt[i] >0)
            {
                lp += i;break;
            }
        }
        StringBuilder sb=new StringBuilder(rp);
        sb.reverse();
        //System.out.println(lp  );
        //System.out.println(rp);
        //System.out.println();
        return lp+ sb;
    }


    public static void addEdge(int u ,int v,HashMap<Integer , ArrayList<Integer> > adj )
    {

        if(adj.containsKey(u) == false)
            adj.put(u,new ArrayList<>());

        if(adj.containsKey(v) == false)
            adj.put(v,new ArrayList<>());

        adj.get(u).add(v);
        adj.get(v).add(u);
    }

    static int max =0 ;
    public static void dfsOnGraph(HashMap<Integer , ArrayList<Integer> > adj ,  int start , int curr)
    {

        var list= adj.get(start);
        if (list == null) return;

        if (curr> max) max   = curr;
        adj.remove(start);
        for(var i : list)
        {
            dfsOnGraph(adj,   i ,curr+1);
        }
    }
    public  static void createGraph(TreeNode root,HashMap<Integer , ArrayList<Integer> > adj)
    {
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);

        while (q.size() > 0 )
        {
           int size = q.size();

           for(int i =0 ;i< size ; i++)
           {
               TreeNode node = q.poll();

               if(node.left!= null)
               {
                   addEdge(node.val,node.left.val,adj);
                   q.add(node.left);
               }
               if(node.right!= null)
               {
                   addEdge(node.val,node.right.val,adj);
                   q.add(node.right);
               }
           }
        }
    }
    public static int amountOfTime(TreeNode root, int start) {

        max =0;
        HashMap<Integer , ArrayList<Integer> > adj = new HashMap<>();
        createGraph(root,adj);
        dfsOnGraph(adj,  start,0 );
        return max;
    }
    public static void main(String[] args) {

//        TreeNode node = new TreeNode(1, new TreeNode(5), new TreeNode(3));
//        node.left.right = new TreeNode(4,new TreeNode(9),new TreeNode(2));
//        node.right.left = new TreeNode(10);
//        node.right.right  = new TreeNode(6);

        TreeNode node = new TreeNode(1);

        System.out.println( amountOfTime(node, 1));
       //System.out.println( largestPalindromic("4040302"));
    }
}
