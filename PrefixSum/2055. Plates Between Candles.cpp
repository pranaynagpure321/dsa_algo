class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> candles;
        //stars
        int n = s.size(), cnt =0;
        int size = queries.size();
        vector<int> prefix(n,0), res(size,0);
       
        for(int i =0 ;i < s.size() ; ++i)
        {
            if(s[i] == '|')
            candles.push_back(i);

            if(s[i] == '*')
            ++cnt;

            prefix[i] =cnt;
        }
         
        for(int k =0 ;k <size ;k++)
        {
           int i = queries[k][0], j = queries[k][1];
           if(i == j || candles.size() ==0) continue;
           if(s[i] !='|')
           {
               auto it = upper_bound(candles.begin(), candles.end(), i);
               i = *it;
           }
           if(s[j] != '|')
           {
               auto it = lower_bound(candles.begin(), candles.end(),j);
               if(it == candles.end()) it = candles.end(), --it;
               while(*it >= j && it != begin(candles)) --it;
               j = *it;
           }

           if(j>=i)
           res[k] = prefix[j]- prefix[i];

        }
        return res;

    }
};



 // short solution
   vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> A, res;
        for (int i = 0; i < s.size(); ++i)
            if (s[i] == '|')
                A.push_back(i);
        for (int q = 0; q < queries.size(); ++q) {
            int i = lower_bound(A.begin(), A.end(), queries[q][0]) - A.begin();
            int j = upper_bound(A.begin(), A.end(), queries[q][1]) - A.begin() - 1;
            res.push_back(i < j ? (A[j] - A[i]) - (j - i) : 0);
        }
        return res;
    }
