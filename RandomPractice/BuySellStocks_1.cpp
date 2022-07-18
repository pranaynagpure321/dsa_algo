#include<algorithm>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int ans =0 ;
        int min =  prices[0] , max = min;
        
    
        for(int i =1 ;i<prices.size(); i++)
        {
             if(prices[i]- min <0 )
             {
                 min = prices[i];
                 max = prices[i];
             }
            
             if(prices[i]> max)
                 max = prices[i];
            
             ans  = std::max(max-min, ans);
        }
        
        return ans;
    }
};
