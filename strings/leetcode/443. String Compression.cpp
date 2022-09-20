class Solution {
public:

   string createString(vector<char>& chars)               // first generate string of like a2b3
    {
        int i =0 , j=0;
        string s="";
        int n = chars.size();
        for ( j = 0; j <n ; ++j) {

            if(chars[i]!=chars[j])
            {
                int win = j-i;
                s += chars[i];
                if(win>1)
                    s+= to_string(win);
                i=j;
            }

        }
        int win = j-i;
        s += chars[i];
        if(win>1)
            s+= to_string(win);

        return s;
    }

    int compress(vector<char>& chars) {

         string s = createString(chars);
         chars.clear();

        for ( char c : s ) {                         // push value of string to vector

            chars.push_back(c);

        }
       // cout<<s;
        
        //time O(n)
        //space O(1)
        return chars.size();

    }
};
