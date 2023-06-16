/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

 //controlled recursion
class BSTIterator {
    Stack<TreeNode>  st;
    public BSTIterator(TreeNode root) {
        this.st =  new Stack<TreeNode>();
        this.inoder_left(root);
    }
    
    public int next() {
        TreeNode node = this.st.pop();
        if(node.right != null)
         inoder_left(node.right);
        return node.val;
    }
    public boolean hasNext() {
        return st.size() > 0;
    }
    void inoder_left(TreeNode root)
    {
        TreeNode p = root;

        while(p != null)
        {
            st.push(p);
            p= p.left;
        }
    }
}
/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */
// c++ code below

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    vector<int> v;
    int i;
    BSTIterator(TreeNode* root) {
        i=0;
        v= vector<int>();
        inoder(root);
    }

    void inoder(TreeNode *root)
    {
        if(root == NULL) return;
        inoder(root->left);
        v.push_back(root->val);
        inoder(root->right);
    }
    
    int next() {
        int a = v[i]; ++i;
        return a;
    }
    
    bool hasNext() {
        if(i< v.size()) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
