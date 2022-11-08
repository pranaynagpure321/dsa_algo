class Solution {
public:
    string makeGood(string s) {
        if(s.length()<2) return s;

        bool isGood =false;
        while(!isGood)
        {
            string tmp=""  ;
            for(int i =1 ;i< s.length(); i++)
            {
                if(s[i]-'a' == s[i-1]-'A' || s[i]-'A' == s[i-1]-'a' )
                {
                    tmp = s.substr(0,i-1) + s.substr(i+1);
                    isGood = false;
                    break;
                }
                else
                isGood = true;
            }
            if(!isGood)
            s =tmp;

            if(s.length()<2) return s;
        }

        return s;
    }
};
