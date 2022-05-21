class Solution {
    public boolean findTarget(TreeNode root, int k) {
        
       boolean ans = help(root,k, new HashSet<Integer>());
       // System.out.println(ans);
        return ans;
        
    }
    public boolean help(TreeNode root, int k, Set<Integer> set) {
        
        if(root==null)
            return false;
        
        boolean left = help(root.left,k,set);
        if(set.contains(k-root.val))
            return true;
        else
            set.add(root.val);
        
        boolean right = help(root.right,k,set);
        
        if(left || right)
            return true;
        
       
        return false;
        
        
    }
    
}
