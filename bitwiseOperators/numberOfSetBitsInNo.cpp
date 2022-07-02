int Solution::numSetBits(unsigned int A) {
   
     int ans=0;
    while (A !=0)
    {
        A = A & (A-1);
        ans++;
        
    }


    return ans;
   
}
int main()
{
    cout<<"Hellfsdfo\n";
    cout<<numSetBits(4294967294);
    return 0;
}
