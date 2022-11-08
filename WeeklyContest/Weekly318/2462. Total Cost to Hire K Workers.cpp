 class ComparisonClass {
    public:
        bool operator() (pair<int, int>& p1, pair<int, int>& p2) {
            if (p1.first == p2.first)
                return p1.second > p2.second;

            return p1.first > p2.first;
        }
    };

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue< pair<int,int>, vector<pair<int, int>> , ComparisonClass > pq1, pq2;


        int i = 0, j = costs.size() - 1;

        while (i < candidates) {
            pq1.push({ costs[i],i });
            pq2.push({ costs[j],j });
            i++; j--;
        }
       // cout<<" pq1=>  " <<pq1.top().first<<" pq2=> "<<pq2.top().first<<" i=> "<<i<<" j=> "<<j<<endl;
       // cout<<"pq1 size=> "<<pq1.size()<<"pq2 size=> "<<pq2.size()<<endl;
        
        long long cost=0;
        while (  k>0 and pq1.size()>0 and pq2.size()>0)
        {
            
            if (pq1.top().first <= pq2.top().first)
            {
               if(pq1.top().first == pq2.top().first  and pq1.top().second == pq2.top().second) pq2.pop();
                
                cost += pq1.top().first;
              //  cout<<"from pq1 "<<pq1.top().first<<endl;
                pq1.pop();
            }
            else if(pq1.top().first > pq2.top().first)
            {
                cost += pq2.top().first;
              //  cout<<"from pq2 "<<pq2.top().first<<endl;
                pq2.pop();    
            }
            
            if(i<=j and pq1.size()<candidates )
                { pq1.push({ costs[i],i }); i++; }
            
            if ( i<=j and pq2.size()<candidates)
                {pq2.push({ costs[j],j }); j--; }
            
         //   cout<<"cost => "<<cost<<endl;
           
            k--;
        }


        while(k>0 and pq1.size()>0)
        {
            cost+= pq1.top().first; pq1.pop(); k--;
        }

         while(k>0 and pq2.size()>0)
        {
            cost+= pq2.top().first; pq2.pop();k--;
        }

        

        return cost;
    }
};
