class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

       stack<int> st;
       int n = heights.size();
       //2,1,5,6,2,3

       vector<int> leftsmaller(n,0);

       for(int i =0 ;i< n;i++)
       {
           int a =heights[i];
           while(!st.empty() and  a<= heights[st.top()])
           {
               st.pop();
           }

           if(!st.empty())
           leftsmaller[i] = st.top()+1;

           st.push(i);
       }

        vector<int> rightsmaller(n,n-1);
        st = stack<int>();
    
      for(int i =n-1 ;i>=0 ;i--)
       {
           int a =heights[i];
           while(!st.empty() and  a<= heights[st.top()])
           {
               st.pop();
           }

           if(!st.empty())
           rightsmaller[i] = st.top()-1;

           st.push(i);
       }


       int area =0;

       for(int i =0 ;i< n ;i++)
       {
           int a = rightsmaller[i]-leftsmaller[i]+1;
           area = max(a*heights[i],area);
       }


        return area;

    }
};
