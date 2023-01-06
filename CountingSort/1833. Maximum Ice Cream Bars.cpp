class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
       
        int n = costs.size();
        int m = *max_element(costs.begin(),costs.end());

        int res =0;

        vector<int> freq(m+1,0);

        for(int &c : costs)
        {
            freq[c]++;
        }

        for(int  i =1 ;i<=m ;i++)
        {   
            if(freq[i] == 0 ) continue;
            
            if(coins < i)
            break;

            int count = min( freq[i] , coins/i);

            coins -= i * count;
            res += count;

        }

        return res;

    }
};

//O(M+N)
