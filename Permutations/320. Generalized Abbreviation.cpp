class Solution {
public:

vector<string> out;
    string encode(string s)                   // to encode string with no of ones
    {
        string  ans ="";
        for (int i =0 ; i<s.length();i++) {

            if(s[i] == '1')
            {
                int cnt =1, j =i+1;
                for(; j<s.length() ;j++)
                {
                    if(s[j]!= '1')
                    { break;}
                    cnt++;
                }
              ans+= to_string(cnt);
                if(j == s.length()) return ans;
                i =j-1;
            }
            else
            {
                ans+= s[i];
            }

        }
       // cout<<ans<<endl;

        return ans;
    }

    void help(int idx , string s)
    {
        if(idx >= s.length())
        {
            out.push_back(encode(s));            // here s will be like 111d or 11r1 and then no of ones will be encoded
            return;
        }

        char c = s[idx];
        string tmp = "";
        if(c>= 97 and c<=122)
        {
            s[idx] ='1';
        }
        //s.erase();
        //pick
        help(idx+1,    s);            // pick means take one char and convert to 1

        s[idx]=c;
        //notpick
        help(idx+1 ,s);            // not pick measn  dont convert char to 1


    }
    vector<string> generateAbbreviations(string word) {

       // cout<<"hello world"<<endl;

       //cout<< encode("aqw111")<<endl;
       out.clear();
        help(0,word);

        return out;


    }
};
