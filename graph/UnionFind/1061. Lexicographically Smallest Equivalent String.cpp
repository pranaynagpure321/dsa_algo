class UnionFind
{
    public:
    vector<int> parent ;
    UnionFind(int n )
    {
        parent.resize(n+1);
        for(int i =0 ;i<= n ;i++)
        parent[i] =i;
    }

    int  findParent(int node)
    {
        if(node == parent[node]) return node;
        return parent[node] =  findParent(parent[node]);
    }

    void unionByRank(int a ,int b)
    {
        int parenta = findParent(a);
        int parentb = findParent(b);

        if(parenta == parentb) return ;

        if(parenta < parentb)
        {
            parent[parentb] = parenta;
        }
        else   
        {
            parent[parenta] = parentb;
        }
    }
};   

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n  = s1.length();
        
        UnionFind *ptr = new UnionFind(26);

        for(int i =0 ;i<n;i++)
        {
            ptr->unionByRank(s1[i]-'a',s2[i]-'a');
        }
        string res ="";
        for(int i =0 ;i<baseStr.size() ;i++)
        {
            char c = (ptr->findParent(baseStr[i]-'a') + 'a');
            res +=c;
        }

        return res;
    }
};
