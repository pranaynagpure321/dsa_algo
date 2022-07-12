double singleMedian(const vector<int> &A)
{
    if(A.size()==1) return A[0];
    
    if(A.size()%2 == 0)
    return (A[A.size()/2] + A[A.size()/2 -1])/2.0;
    
    return A[A.size()/2];
}


double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
 
    if(A.size()==0 ) return singleMedian(B);
    if(B.size()==0) return singleMedian(A);

    int n1= A.size() ,n2= B.size();
    if(A.size()> B.size()) return findMedianSortedArrays(B,A);
   

   int low=0,high=n1;
   

    while (low<=high)
    {
        int slice1 =(low+high)/2 ;
        int slice2  =  (n1+n2+1)/2  - slice1;

        int x1 = slice1==0? INT_MIN :  A[slice1-1];
        int  x2 = slice1==n1? INT_MAX : A[slice1];
        int y1  = slice2==0? INT_MIN :  B[slice2-1] ;
        int  y2 = slice2==n2? INT_MAX : B[slice2];
        if(x1<=y2 && y1<=x2)
        {
            if((n1+n2)%2 ==0 ) 
            return (max(x1,y1) + min(x2,y2))/2.0;

            return max(x1,y1);
        }
        else if(x1 > y2 )
        {
           high =slice1-1;
        }
        else 
        {
            low= slice1+1;
        }
         
        
    }
      
    return -1.0;
}
