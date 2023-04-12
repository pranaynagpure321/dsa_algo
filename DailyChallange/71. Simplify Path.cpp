class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        for(int i =0 ;i < path.size(); i++)
        {
            if(path[i] == '/') continue;
            string temp ;

            while(i < path.size() and path[i] != '/') temp += path[i++];

            if(temp == ".") continue;
         
            else if(temp == ".." )
            {
                if( st.size()>0 ) st.pop();
            }   
            else st.push(temp);
        }

        string ans ="";
        while(st.size()>0)
        {
            ans =  "/"+st.top() + ans;
            st.pop();
        }
        if(ans.size() ==0 ) return "/";
        return ans;
    }
};
