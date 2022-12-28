class Solution {
public:
 
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        
        priority_queue< int, vector<int>, greater<int>> pq;

        int cnt =0;
        for(int i =0 ;i< capacity.size(); i++)
        {
            int diff = capacity[i]-rocks[i];

            if(diff==0) 
            {
                cnt++; continue;
            }
            else
            {
                pq.push(diff);
            }
        }


        while(additionalRocks>=0 and pq.size()>0)
        {
            if(additionalRocks- pq.top()  >=0 )
            {
                additionalRocks -= pq.top() ;
                pq.pop();
                cnt++;
            }
            else break;
        }

        return cnt;
    }
};
