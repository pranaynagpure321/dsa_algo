class unionFind
{
    public:
    vector<int> parent;
    unionFind(int n)
    {
        parent.resize(n+1);
        for(int i =0 ;i<=n ;i++)
        parent[i] =i;
    }

    int findParent(int node)
    {
        if(node == parent[node])
        return node;

        return parent[node] = findParent(parent[node]);
    }

    void unionBy(int a, int b)
    {
        int pa = findParent(a) , pb = findParent(b);
        if(pa == pb) return;
        if(pa< pb)
        {
            parent[pb] = pa;
        }
        else 
        {
            parent[pa] = pb;  
        }
    }
};

class Solution {
public:

    bool checkParentOfALL(unionFind *ptr, int n)
    {
        int parent =0;
        for(int i =0 ;i< n ;i++)
        {   
            if(i ==0 )
            parent = ptr->findParent(i);

            else if (parent != ptr->findParent(i))
            {
                return false;
            }
        }
        return true;
    }

    int earliestAcq(vector<vector<int>>& logs, int n) {
        
        sort(begin(logs),end(logs));
        unionFind *ptr = new unionFind(n);
        int cnt =0;
        for(int i =0 ;i< logs.size() ;i++)
        {
            int time = logs[i][0];
            int a = logs[i][1];
            int b = logs[i][2];

            ptr->unionBy(a, b);
            cnt++;
            if(cnt >= n/2 && checkParentOfALL(ptr,n)) return time;
        }

        return -1;
    }
};
