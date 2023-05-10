class Solution {
    public int[][] generateMatrix(int n) {
        int[][] res = new int[n][n];


        int row = 0, col =0 , rowend = n-1 , colend = n-1, val =1;

        while(val <= n*n)
        {
            for(int j = col ; j<= colend ; ++j )
            res[row][j] = val++;

            row++;
            for(int i = row; i<=rowend ; ++i)
            res[i][colend] = val++;

            colend--;

            for(int j = colend; j>=col ;--j)
            res[rowend][j] = val++;

            rowend--;

            for(int i =rowend ;i>=row ;--i)
            res[i][col] = val++;

            col++;

        }
        
        return res;
    }
}
