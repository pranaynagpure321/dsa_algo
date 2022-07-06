int singleNumber(const vector<int> &A) {
    
    int b =0;
    for(int i =0;i<A.size();i++)
    {
       b = b ^ A[i];
       
    }
    return b;
}
