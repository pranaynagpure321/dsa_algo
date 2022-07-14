int findUpperBound_2 (vector<int> &A  , int bound)
{
    int min = 0, max= A.size()-1;
    while (min<= max)
    {
         int mid = (min + max) >> 1;

         if(bound < A[mid])
         max = mid -1;

         else 
          min = mid + 1;
    }
    return min;    
}

int Solution::findMedian(vector<vector<int> > &A) {
    //find min ans max
 int r = A.size();
 int c = A[0].size();
 
 int min = 1 , max = 1e9;

    while (min<=max)
    {
        int mid = (min +max) >> 1;
        int count =0;
        for(int i =0 ;i<r ;i++)
         //count += upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin();
         count += findUpperBound_2(A[i],mid);

         if(count> r*c/2)
          max = mid -1;

          else 
            min = mid +1;
    }
        return min;
}
