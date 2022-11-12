#define ll long long 
class Solution {
public:

    void div(stack<ll> &st)
    {
        if(!st.empty())
        {
            ll a = st.top();
            st.pop();
            ll b = st.top(); st.pop();
            ll c = b/a;
            st.push(c);
        }
    }

    void mul(stack<ll> &st)
    {
         if(!st.empty())
        {
            ll a = st.top();
            st.pop();
            ll b = st.top(); st.pop();
            ll c = b*a;
            st.push(c);
        }
    }
    void sub(stack<ll> &st)
    {
        if(!st.empty())
        {
            ll a = st.top();
            st.pop();
            ll b = st.top(); st.pop();
            ll c = b-a;
            st.push(c);
        }
    }
    void add(stack<ll> &st)
    {
       if(!st.empty())
        {
            ll a = st.top();
            st.pop();
            ll b = st.top(); st.pop();
            ll c = b+a;
            st.push(c);
        }
    }

    int evalRPN(vector<string>& tokens) {
        
        stack<ll> st;
        int i=0;
        while(i<tokens.size())
        {
            string tk =tokens[i++];

            if(tk == "+") add(st);
            else if (tk == "-") sub(st);
            else if(tk == "*") mul(st);
            else if (tk == "/") div(st);

            else
            {
                st.push(stoll(tk));
            } 
        }
        //time O(N)
        int res = st.top();
        return res;
    }
};
