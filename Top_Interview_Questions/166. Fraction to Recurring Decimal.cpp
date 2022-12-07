#define ll long long

class Solution {
public:
    string fractionToDecimal(int n, int d) {
        
        if(d== 1) return to_string(n);
        if(n ==0) return "0";
       
        ll divident = abs(n);
        ll divisor = abs(d);
        ll remainder = divident%divisor;

        int sign = (n<0)?-1 :1;
        sign = (d<0) ? -sign :sign;

        string res = to_string(divident/divisor);

        if(remainder == 0 )
        return  res;

        if(sign == -1)    
           res = "-"+res;
        
        string tmp ="";
        unordered_map<int, int> mp;

        while(remainder !=0 )
        {
            if(mp.count(remainder))
            {
                int size = mp[remainder];
                res += "." + tmp.substr(0,size) +"("+ tmp.substr(size) + ")";
                return res;
            }

            mp[remainder] =tmp.length();
            remainder*=10;
            tmp += to_string(remainder/divisor);
            remainder = remainder%divisor;
        }

        return res + "."+tmp;
    }
};
