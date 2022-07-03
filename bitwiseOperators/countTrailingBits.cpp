int Solution::solve(int A) {

    int ans=0;
    while((A & 1) != 1)
    {
        ans++;
        A >>=1;
        
    }
    return ans;
}
