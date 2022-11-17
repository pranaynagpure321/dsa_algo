class Solution {
public:
    int calculate(string s) {
        
       stack<long long> st;
        int len =s.length();
       long long num =0;
       char sign ='+';
       for(int i =0 ;i <s.length(); i++)
       {    
           char ch = s[i];
           if(isdigit(ch))
           {
               num = 10L*num + ch-'0';
           }
           if( !isdigit(ch) and !iswspace(ch) || i ==len-1)
           { 

               if(sign == '-')
               st.push(-num);

               if(sign == '+')
               st.push(num);

               if(sign == '*')
               {
                 int a = st.top(); st.pop();
                 st.push(a*num);
               }
                if(sign == '/')
               {
                 int a = st.top(); st.pop();
                 st.push(a/num);
               }

               sign = s[i];
               num =0;
           }
       }

       int ans =0;

       while(!st.empty())
       {
           ans += st.top();
           st.pop();
       }
      
      
      //time O(N)
      //spce O(N)
      return ans;

    }
};
