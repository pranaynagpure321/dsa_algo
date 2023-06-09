class ComparisonClass
{
    public:
    bool operator() ( pair<int,int> &p1 , pair<int,int> &p2)
    {
        return p1.first + p1.second < p2.first+p2.second;
    }
};
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& n1, vector<int>& n2, int k) {
    
        vector<vector<int>> res;
        priority_queue<pair<int,int>, vector<pair<int,int>>, ComparisonClass> pq;
        for(int i =0 ; i< n1.size(); i++)
        {
            for(int j =0 ; j<n2.size() ; j++)
            {
                if(pq.size()<k )
                pq.push({n1[i],n2[j]});

                else if(n1[i] + n2[j] < pq.top().first + pq.top().second)
                {
                    pq.pop();
                     pq.push({n1[i],n2[j]});
                }
                else
                break;
            }
        }
        while(pq.size()>0)
        {
            res.push_back({pq.top().first, pq.top().second});
            pq.pop();
        }
 
        return res;
    }
};
