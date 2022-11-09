class StockSpanner {

    Stack<Pair<Integer,Integer>> st;
    
    public StockSpanner() {
        st = new Stack<>();
    }
    
    public int next(int price) {
        
        int ans =1;

        while(!st.isEmpty() && st.peek().getKey() <= price)
        {
            ans += st.pop().getValue();
        }

        st.push(new Pair(price,ans));

        return ans;
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */
 
 
 //my own solution 
class Node
{
    public:
    int val;
    int currSpanner;
    Node *PreViousGreater ;
    Node(int v, int spanner)
    {
        val =v;
        currSpanner =spanner;
        PreViousGreater =NULL;
    }
};

class StockSpanner {
public:

// keep track of previous gretar element node and also the count of consecutive elements from
// form current element (currSpanner)
// read above node class to understand more about it
    vector<Node*> vec;
    StockSpanner() {
        //vector to store all the pointer to Nodes
        vec = vector<Node*>();
    }
    
    int next(int price) {
        
        Node *tmp = vec.size()>0? vec[vec.size()-1]: NULL;
        int spanner =0;
        while(  tmp!=NULL  and tmp->val <= price)             //else find the previous greater until then add all the spanner to current spanner
        {
            spanner += tmp->currSpanner;
            tmp = tmp->PreViousGreater;
        }

        Node *n = new Node(price,spanner+1);
        
        if(tmp!=NULL)          // assign previous greater element to current element
        n->PreViousGreater = tmp;
        vec.push_back(n);
        
        return spanner+1;

    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
