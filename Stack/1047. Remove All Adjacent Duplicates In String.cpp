class Solution {
public:
    string removeDuplicates(string s) {
        
        bool isStringGood=false;

        stack<char> st;
        int i =0;
        st.push(s[i++]);

        while(i<s.length())
        {   
            if(!st.empty() and st.top() == s[i])
            {st.pop(); }
            else 
            st.push(s[i]);
            i++;
        }

        string tmp ="";
        while(!st.empty())
        {
            tmp = st.top() +tmp; st.pop();
        }
        //reverse(tmp.begin(),tmp.end());
        //time O(n)
        // space O(N)
        // interesting two  pointer approach https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/solutions/1869210/two-pointers/
        return tmp;

    }
};
