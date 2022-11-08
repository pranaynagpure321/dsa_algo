class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstRow = false, firstCol = false;
        //used first row and col to store the information
        //whenever you face inplace question find a way to store infromation in structure itself to use later

        for (int j = 0; j < matrix[0].size(); j++)
            if (matrix[0][j] == 0) {firstRow = true; break;}

        for (int i = 0; i < matrix.size(); i++)
            if (matrix[i][0] == 0) {firstCol = true; break;}



        //checking from 2nd row and 2nd col if found zero then we store that info in first row and first col
        for (int i = 1; i < matrix.size(); i++)
        {
            for (int j = 1; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // now based on first row and col we can update other values
        for (int i = 1; i < matrix.size(); i++)
        {
            for (int j = 1; j < matrix[0].size(); j++)
            {
                if (matrix[0][j] == 0 || matrix[i][0] == 0)
                    matrix[i][j] = 0;
            }
        }

        //if first row had any zeros from start then set that row to zero
        if(firstCol)
        for (int i = 0; i < matrix.size(); i++)
        {
            matrix[i][0] = 0;
        }

        //similar to first col
        if(firstRow)
        for (int j = 0; j < matrix[0].size(); j++)
        {
            matrix[0][j] = 0;
        }
        
    }
};
