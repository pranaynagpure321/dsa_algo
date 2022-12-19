class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int> st;
        vector<int> res(t.size(),0);
        for(int i =0 ;i<t.size() ;i++)
        {
            while(!st.empty() && t[i]>t[st.top()])
            {
                int idx = st.top();
                res[idx] = i-idx;
                st.pop();
            }

            st.push(i);
        }
        //O(N)
        return res;
    }
};
