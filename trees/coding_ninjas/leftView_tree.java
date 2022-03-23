import java.util.ArrayList;

public class Solution 
{
    static int maxlength=0;
    public static void dfs(TreeNode<Integer> root,int count)
    {

        if(root.left==null || root.right==null){
           if(maxlength<count)
               maxlength=count;
        }
        
        //left traversal
        if(root.left!=null)
         dfs( root.left , count+1);
        
        if(root.right!=null)
        dfs(root.right,count+1);
        
    }
    public static void postorder(TreeNode<Integer> root,int[] levels,int i )
    {
       
        if( levels[i]==0 && root!=null)
        levels[i]=root.data;
        
        if(root.left != null)
        postorder(root.left,levels,i+1);
        
        if(root.right != null)
        postorder(root.right,levels,i+1);
        
    }
    public static ArrayList<Integer> getLeftView(TreeNode<Integer> root) 
    {
        if(root!=null)
        dfs(root,1);
       // System.out.println("hi=> "+maxlength);
        ArrayList<Integer> arr = new ArrayList<>();
        int [] levels = new int[maxlength];
        if(maxlength>0)
        postorder(root,levels,0);
        maxlength=0;
        
        for(int i : levels)
        {
            arr.add(i);
        }
        
       return arr;
    }
}
