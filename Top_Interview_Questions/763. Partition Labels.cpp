class Solution {
public:
    vector<int> res;

    bool isValid(string s ,int i , int j)
    {
        int a =0, b=0;

        for(int  k =i ; k<=j && k<s.size() ;k++)
        {
            a = a | (1<<(s[k]-'a'));
        }

         for(int  k =j+1 ;  k<s.size() ;k++)
        {
            if(a & (1<<(s[k]-'a'))) return false;
        }

        return true;
    }
    vector<int> partitionLabels(string s) {
        
        int i =0;

        for(int j =0 ;j< s.size(); j++)
        {
            if(isValid(s,i,j))
            {
                res.push_back(j+1 -i);
                i = j+1;
            }
        }

        return res;
    }
};
