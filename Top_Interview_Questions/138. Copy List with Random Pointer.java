/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        //make copy and adjust random poninters

         
        Node secHead= new Node(0);
        Node tmp = secHead;
        Node t = head;
        int i=0;
        HashMap<Node,Integer  > h1 = new HashMap<Node,Integer>();
        HashMap<Integer, Node  > h2 = new HashMap<Integer,Node>();
        while(t!=null)
        {
            h1.put(t,i);
            tmp.next = new Node(t.val);
            tmp= tmp.next;
            t = t.next;
            h2.put(i,tmp);
            i++;
        }
        
        
        for (var p : h1.keySet())
        {
            int idx = h1.get(p);
            Node random = p.random;

            if(random!= null){
            int pointedIdx = h1.get(random);
            
            h2.get(idx).random = h2.get(pointedIdx);
            }
        }
        
        return secHead.next;

    }
}
