class Solution {
public:
     char low(vector<int>& fre)
    {
        for (int i = 0; i < fre.size(); i++)
        {
            if (fre[i] != 0)
                return 'a' + i;
        }

        return 'a';
    }
    string robotWithString(string s) {

      vector<int> v(26, 0);

        for (char ch : s)
            v[ch - 'a']++;

        string res = "";
        stack<int> st;
        for (char c : s)
        {
            st.push(c);
            v[c - 'a']--;

            while (st.size() >0 and st.top()<= low(v))
            {
                res += st.top();
                st.pop();
            }
        }


        while (st.size() > 0) {
            
            res += st.top();
            st.pop();
        }
        
        return res;
    }
};
