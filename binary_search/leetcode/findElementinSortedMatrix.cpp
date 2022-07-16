class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        
        int min = 0 , max = matrix.size()*matrix[0].size() - 1 ;
        int mod = matrix[0].size();
        
        while(min <= max)
        {
            
            int mid = (min + max) >> 1;
            int row = mid / mod;
            int col = mid % mod;
            
            if(matrix[row][col] == target) return true;
            if(matrix[row][col] > target)
                max = mid - 1;
            else
                min = mid + 1;      
        }
        
        return false;
        
    }
};
