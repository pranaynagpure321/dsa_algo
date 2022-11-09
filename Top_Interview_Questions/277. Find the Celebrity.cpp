/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    vector<vector<int>> cache;

    bool knows_2(int i,int j)
    {
        if(cache[i][j] == 1) return true;
        if(cache[i][j] == 0) return false;

        bool  ans =  knows(i,j);
        cache[i][j] =ans == true ? 1: 0;
        return ans;
    }
    /* The knows API is defined for you.
      bool knows(int a, int b); */

 
    bool check(int i,int n )
    {
        bool isCelebrity = true;
        for(int j =0 ;j<n; j++)
        {
            if(i!=j and knows_2(i,j))
            {
                isCelebrity =false;
                break;
            }
        }

        if(isCelebrity)
        {
            for(int j =0 ;j<n ;j++)
             if(i!=j and !knows_2(j,i)) 
             {isCelebrity = false; break;}

        }

        return isCelebrity;
    }

    int findCelebrity(int n) {
        
       int isCelebrity =0;
       cache = vector<vector<int>>(n,vector<int>(n,-1));
       for(int i =0 ;i<n;i++ )
       {
           if(isCelebrity!=i and knows_2(isCelebrity,i))
           {
              isCelebrity =i;
           }
           if(check(i,n))
           return i;
       }
        //time O(N2)
        return -1;
    }
};
