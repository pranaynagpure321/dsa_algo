class Solution {
public:
    int i ;
    int emptyStack(stack<int> & st)
    {
        int ans =0;
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
    int dfs(string s)
    {
        i++;
        if(s.length() ==i ) return 0;
        long long num = 0;
        int len = s.length();
        stack<int> st;
        char sign = '+';

        for( ;i< s.length(); i++)
        {
            char ch  =s[i];
            if(ch == '(')
            {
                int t = dfs(s);
                if(sign == '-') st.push(-t);
                else st.push(t);
            }
            if(isdigit(ch))
            {
                num = num*10 + (ch-'0');
            }
            if(!isdigit(ch) && !iswspace(ch) || i==len -1 )
            {
               if(sign == '+')
                    st.push( num);
               else if(sign == '-')
                    st.push( -num);
               
                sign = ch;
                num = 0;
            }
            if(ch == ')') return emptyStack(st);
        }

       return emptyStack(st);
    }
   
    int calculate(string s) {
        
       i =-1;
       return dfs(s);
    }
};
