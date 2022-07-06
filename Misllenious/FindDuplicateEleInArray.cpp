int findDulicate(vector<int> &A)
{

    //method explanation https://keithschwarz.com/interesting/code/?dir=find-duplicate
    //https://stackoverflow.com/a/56413628
    int slow =A[0];
    int fast =A[A[0]];

    while (slow != fast)
    {

       slow = A[slow];
       fast = A[A[fast]];
    }

    if(slow != fast) return -1;
    slow=0;

    while(slow!=fast)
    {
        slow = A[slow];
        fast = A[fast];
    }
    
   return slow;
}
