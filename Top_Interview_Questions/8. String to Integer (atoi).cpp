class Solution {
public:

    void removeSpaceAndWord(string &s)
    {
        
        if(s[0] >= 65 and s[0]<= 122) return;
        string tmp = "";
        bool isLead = true;
        for(int i =0 ;i<s.size() ;i++)
        {
           if(s[i]== ' ' &&  isLead)continue;
           else if(((s[i]-'0'>=0 and s[i]-'0'<=9) || s[i]=='+' || s[i]=='-') )
           {
               tmp +=s[i];
               isLead = false;
           }
           else
           break;
        }

        s =tmp;
        return ;
    }
    int myAtoi(string s) {

        if(s.size()==0) return 0;      
        removeSpaceAndWord(s);
        if(s.size()==0) return 0;   
        if(s[0] >= 65 and s[0]<= 122) return 0;
        cout<<s.size()<<endl;
        int sign = 1;
        long long num =0;
         
        for(int i=0;i<s.size();i++)
        {
            char ch = s[i];
            if(ch == '+' || ch =='-' )
            {
                if(i!=0) break;
                sign = (ch=='-')? -1*sign :sign; 
            }
            else if(ch == '.') break;
            else
            {
                num = num*10 + ch-'0';
                if(num> (1LL<<31)) break;
            }
        }

        if(sign == -1)
        {
            return (-num <INT_MIN)? INT_MIN : -num;
        }
        //time O(s.length)
        return (num >INT_MAX)? INT_MAX : num;;
    }
};
