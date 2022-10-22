/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    
    vector<int> list;
    int pos;

    NestedIterator(vector<NestedInteger> &nestedList) {
        
        //convert conplete list to int list
        //use recursive
        iterativeFlattnedList(nestedList);
        pos =0;
    }
    //below is iterative program to flattned list
    void iterativeFlattnedList(vector<NestedInteger> &nestedList)
    {
         stack<pair<vector<NestedInteger>,int>> st;  // storing curerrnt nestedlist and index to start for cur list
        st.push({nestedList,0});
        while(!st.empty())
        {
            auto curlist =st.top().first;
            int i = st.top().second;                   //start interation from previoult stopped index
            st.pop();
            
            for( ;i<curlist.size(); i++)                        // iterate the curr list 
            {
                if(curlist[i].isInteger())
                    list.push_back(curlist[i].getInteger());
                else                                             // if next element is list then push cur list to stack with next indx and then push second list to stack with idx=0
                {
                    if(i+1<curlist.size())
                    st.push({curlist,i+1});
                    st.push({curlist[i].getList(),0});
                    break;
                }
            }
        }
    }
    
    
    // below is recursive program to flattned list
    void convertToFlattnedList(vector<NestedInteger> &nestedList)
    {
        for(auto nest : nestedList)
        {
            if(nest.isInteger())
                list.push_back(nest.getInteger());
            else
                convertToFlattnedList(nest.getList());
        }
    }
    
    int next() {
        
        return list[pos++];
    }
    
    bool hasNext() {
        if(pos>= list.size())
            return false;
        return true;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
