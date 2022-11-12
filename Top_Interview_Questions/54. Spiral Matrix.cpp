class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> res;
        int endRow = matrix.size(), endCol = matrix[0].size();
        int stRow =0 ,stCol=0;
        string direction = "left";
        int row =0, col =0;
        while(res.size() < (matrix.size()*matrix[0].size()))
        {

            if(direction == "left")
            {
                row= stRow;
                for( col = stCol; col<endCol ;++col)
                res.push_back(matrix[row][col]);
                 
                direction = "down";
            }
            else if(direction == "down")
            {
                col =endCol-1;
                for(row = stRow+1 ; row<endRow ; ++row)
                res.push_back(matrix[row][col]);
                direction = "right"; 
            }
            else if(direction == "right")
            {
                row = endRow-1;
                for(col =endCol-2; col>=stCol ;col-- )
                  res.push_back(matrix[row][col]);
                direction = "up";
                stRow++;endRow--;
            }
            else
            {
                col =stCol;
                for(row = endRow-1; row>=stRow; row--)
                res.push_back(matrix[row][col]);

                direction ="left";
                endCol--;stCol++;

            }

        }
        //time O(M*N)

        return res;
    }
};
