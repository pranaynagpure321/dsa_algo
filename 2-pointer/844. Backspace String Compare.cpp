/*Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

 

Example 1:

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".*/


class Solution {

    string getRemainingStr(string s)
    {
         
         for(int i =0 ;i<s.length() ; i++)
        {
            if(s[i] == '#')
            {
                int t = i-1;
                
                while(t >= 0)
                {
                    if(s[t] == '#')
                        t--;
                    else
                    {  s[t] = '#'; break;}
                }
                
            }
        }
        
        
        s.erase(remove(s.begin(),s.end(),'#'),s.end());
        //erase(s, '#');
        
        return s;
    }
    
public:
    bool backspaceCompare(string s, string t) {
        
       
       s= getRemainingStr(s);
        cout<<s<<endl;
       t = getRemainingStr(t);
          cout<<t<<endl;
        
        
        return s == t;
        
        
    }
};
