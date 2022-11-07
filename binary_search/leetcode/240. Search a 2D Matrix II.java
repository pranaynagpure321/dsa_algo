class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int row =matrix.length-1, col =0;


        while(row>=0 && col < matrix[0].length)
        {
            if(matrix[row][col] == target) return true;

            if(matrix[row][col] > target)
            row--;
            else
            col++;
        }

        return false;
    }
}


// my approach in cpp
class Solution {
public:

    bool binarySearch(vector<int>& arr,int t)
    {
        int min =0, max= arr.size()-1;
        while(min <= max)
        {
            int mid = (min+max)>>1;

            if(arr[mid] == t) return true;

            if(arr[mid] < t) min = mid +1;

            else max = mid -1;
        }
        //if(arr[min]==t ) return true;
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        for(auto & row : matrix)
        {
            if(row[0]<= target and target <= row[row.size()-1]  and binarySearch(row,target))
            return true;
        }
        return false;
    }
};
