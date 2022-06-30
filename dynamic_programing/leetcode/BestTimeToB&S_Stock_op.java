class Solution {
    public int maxProfit(int[] prices) {
        
        int i = 0, j=0;
        
        int profit =0;

        for (int k =1;k< prices.length;k++) {
        
            if(prices[k] < prices[i])
            {
               i = k; 
            }
            
           else  if (prices[k] > prices[i])
            {
                j=k;
            }
            
            if  ( j>i && (prices[j]-prices[i])>profit)
                profit = prices[j]-prices[i];   
        }
        return profit;
        
    }
}
