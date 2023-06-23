class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
     
        set<string> pool; // instantly find the mutation 
        for(auto &s : bank)
        pool.insert(s);

        queue<string> q;
        q.push(startGene);

        int level =0;

        while(q.size()>0)
        {
            int size = q.size();

            for(int i =0 ;i< size ; ++i)   // interate over the current level ang generate all the possible nodes
            {
                string node = q.front(); q.pop();

                if(node == endGene) return level;   //if current value matches the endstring return level;

                for(char c : "ATCG")      // replace every character in current string with ATCG 
                {
                    for(int j =0 ;j<node.size() ; ++j)
                    {
                        int t = node[j];
                        node[j] = c;

                        if( pool.find(node) != pool.end())   // if found in pool push in queue and erase from the pool
                        {
                            q.push(node); 
                            pool.erase(pool.find(node));
                        }

                        node[j] = t;
                    }
                }
            }
            level++;
        }
        return -1;
        
    }
};
