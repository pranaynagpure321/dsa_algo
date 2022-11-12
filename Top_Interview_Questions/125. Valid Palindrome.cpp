class Solution {
public:
    bool isPalindrome(string s) {

        string tmp="";
        //cout<<(int)'9'<<endl;
        for(char &ch : s)
        {
            if((ch>= 65 and ch<= 90) ||(ch>= 97 and ch<= 122) || (ch>= 48 and ch<= 57) )
            {
                if(ch>= 65 and ch<= 90)
                {
                    int t = ch- 'A';
                    tmp += ('a'+t);
                }
                else
                {
                    tmp += ch;
                }
            }
        }

        int i=0 ,j = tmp.length()-1;

        while(i<=j)
        {
            if(tmp[i++]!=tmp[j--])return false; 
        }
      //time o(N)
        return true;
    }
};
