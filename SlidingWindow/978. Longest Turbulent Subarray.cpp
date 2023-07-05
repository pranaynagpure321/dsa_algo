class Solution {
public:

    int cmp(int a , int b)
    {
        if(a==b)
        return 0;

        if(a<b)
        return 1;

        return -1;
    }
    int maxTurbulenceSize(vector<int>& arr) {

       int n = arr.size();

       int ans = 1;
       int i =0;

       for(int j = 1 ;j<n ;++j)
       {
           int c = cmp(arr[j-1],arr[j]);

           if(c ==0 )
           i =j;
           else if(j == n-1 || c*cmp(arr[j],arr[j+1]) != -1)
           {
               ans =max(ans,j - i +1);
               i=j;
           }
       }

        return ans;
    }
};
