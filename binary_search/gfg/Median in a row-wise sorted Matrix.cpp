//{ Driver Code Starts
//Initial template for C++
/*
Given a row wise sorted matrix of size R*C where R and C are always odd, find the median of the matrix.

Example 1:

Input:
R = 3, C = 3
M = [[1, 3, 5], 
     [2, 6, 9], 
     [3, 6, 9]]
Output: 5
Explanation: Sorting matrix elements gives 
us {1,2,3,3,5,6,6,9,9}. Hence, 5 is median. 

*/

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    
    int count_less(  vector<vector<int>> & matrix , int m, int n, int mid)
    {
        int cnt =0;
        for(int row = 0 ; row < m; row++)
        {
            cnt += upper_bound(matrix[row].begin(), matrix[row].end(), mid) - matrix[row].begin(); // calculate upper bound so that we know which elements are smaller that we so we can get count for it
        }
        return cnt;
    }

    int median(vector<vector<int>> &matrix, int R, int C){
        // code here     
        
        int mi = INT_MAX , mx = INT_MIN;
        
        for(int i =0 ; i< R ; i++)
        {
            mx = max(mx, matrix[i][C-1]);
            mi = min(mi, matrix[i][0] );         // define search space on mi element is 0,0 andmax element is R,C
        }
        
        int req  = (R*C)/2;
        while(mi <= mx)
        {
            int mid = mi + (mx - mi)/2;
            int cnt = count_less(matrix, R,C, mid);
            
            if(req < cnt)
            mx = mid-1;
            else mi = mid+1;
        }
        
        return mi;
    }
};
//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends
