//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long A1[], long long A2[], int n, int m) 
        { 
            // code here 
            int i =n-1, j =0;
            while(i >=0  and j <m)
            {
                if(A1[i] > A2[j])
                {
                    swap(A1[i] , A2[j]);
                    i--; j++;
                }
                else
                break;
            }
            
            sort(A1, A1+n);
            sort(A2,A2+m);
            
        } 
};

// } Driver Code Ends
