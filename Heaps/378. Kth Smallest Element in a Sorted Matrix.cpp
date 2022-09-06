/*378. Kth Smallest Element in a Sorted Matrix
Medium

Share
Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

You must find a solution with a memory complexity better than O(n2).

Example 1:

Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13
Example 2:

Input: matrix = [[-5]], k = 1
Output: -5*/

int kthSmallest(vector<vector<int>>& matrix, int k) {

    //incomplete
    // fails for [[1,2],[1,3]] k =2 Expectedop= 1; myop= 2; 
    int n = matrix.size();
    int i =0 ,j= n*n -1;

    
    while (i <= j)
    {
        int mid = (i+j)/2;

        int row = mid / n;
        int col = mid % n;

        if(mid == k-1)
        {

            return matrix[row][col];
        }
       

        if(mid < k)
         i = mid +1;

        else j = mid -1;
    }
    
    return INT_MIN;
}


class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
    
        priority_queue<int> pq;

        for(auto &i : matrix)
        {
            for(auto &j : i)
            {
                pq.push(j);
            }
        }
        
        k = pq.size() -k;
        while (k--)
        {
            pq.pop();
        }

        
        //time (m*nlogn)
        return pq.top();
        
        
    }
};
