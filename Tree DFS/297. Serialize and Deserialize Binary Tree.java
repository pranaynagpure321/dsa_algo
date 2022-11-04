/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    // Encodes a tree to a single string.

    public String rSerial(TreeNode root)
    {
        if(root == null) 
        {
            return "null";
        }
        String tmp  =  ""+ root.val+","; 

        tmp+= rSerial(root.left) +",";
        tmp+= rSerial(root.right);

        return tmp;

    }

    public String serialize(TreeNode root) {
        String s =  rSerial(root);
        System.out.println(s);
        return s;
    }

    // Decodes your encoded data to tree.

    public TreeNode rDeserial(List<String> data)
    {
        if(data.get(0).equals("null"))
        {
            data.remove(0);
            return null;
        }

        TreeNode root = new TreeNode(Integer.valueOf(data.get(0)));
        data.remove(0);

        root.left = rDeserial(data);
        root.right = rDeserial(data);

        return root;

    }

    public TreeNode deserialize(String data) {
        
        String[] str = data.split(",");

        List<String> list = new LinkedList<String>(Arrays.asList(str));

        TreeNode root = rDeserial(list);
        return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// TreeNode ans = deser.deserialize(ser.serialize(root));
