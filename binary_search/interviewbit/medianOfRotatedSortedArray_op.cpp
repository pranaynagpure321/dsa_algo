int findMedian_2(vector<vector<int> > &A) {


  
 int r = A.size();
 int c = A[0].size();
 
 int min = 1 , max = 1e9;

    while (min<=max)
    {
        int mid = (min +max) >> 1;
        int count =0;
        for(int i =0 ;i<r ;i++)
         count += upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin();


         if(count> r*c/2)
          max = mid -1;

          else 
            min = mid +1;



    }
    
        return min;
}

int main()
{
    vector<vector<int>> vect
    {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };

    vector<vector<int>> vect2
    {
        {2, 3, 3},
        {1, 5, 6},
        {6, 6, 7}
    };

    vector<vector<int>> vect3
    {
        {1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3}
    };

     vector<vector<int>> vect4
    {
        {2},
        {1},
        {4},
        {1},
        {2},
        {2},
        {5}
    };

    cout<<findMedian_2(vect4);
    
}
