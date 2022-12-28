class Solution {
public:
    int floor(int a )
    {
        return (a%2 == 0)? a/2 : (a/2 +1);
    }
    int minStoneSum(vector<int>& piles, int k) {
        
        priority_queue<int> pq;
        int sum =0;
        for(int a : piles)
        {
            sum += a;
            pq.push(a);
        }

        while(k>0)
        {
            k--;
            int a  = pq.top();
            sum = sum - a + floor(a);

            pq.pop();
            pq.push(floor(a));
        }

        return sum;
    
    }
};
