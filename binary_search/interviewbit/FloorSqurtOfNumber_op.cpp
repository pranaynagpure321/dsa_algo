int  sqrt(int A) {
    
    if(A ==0 ) return 0;
    long long min =1, max= A;

    while (min<=max)
    {
        long long mid = (min +max) >> 1;

        if( mid*mid <= A)
         min = mid +1;

        else  
        max = mid -1;
    }
    
    return min-1;
    
}
int main()
{
    cout<<sqrt(2147483647);
}
