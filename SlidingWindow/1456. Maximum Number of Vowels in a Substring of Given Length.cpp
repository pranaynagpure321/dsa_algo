class Solution {
public:
    bool isvovel(char &c)
    {
        return c == 'a' || c=='e' || c == 'i' || c == 'o'|| c == 'u';
    }
    int maxVowels(string s, int k) {
        deque<char> dq;
        int j =0, res =0;
        for(int i =0 ;i<s.size(); ++i)
        {
            if(dq.size()<k and isvovel(s[i]))
            {
                dq.push_back(s[i]);
            }
            int sz = dq.size();
            res = max(res,sz);
            if(res == k) return k;

            while(i-j+1>=k)
            {
                if(isvovel(s[j]))
                dq.pop_front();
                j++;
            }
        }

        return res;
    }
};
