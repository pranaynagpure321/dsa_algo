// { Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG
{
    public static void main(String args[])throws IOException
    {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        
        while(t-- > 0)
        {
            String str[] = read.readLine().trim().split("\\s+");
            int r = Integer.parseInt(str[0]);
            int c = Integer.parseInt(str[1]);
            int matrix[][] = new int[r][c];
            
            for(int i = 0; i < r; i++)
            {
                int k = 0;
                str = read.readLine().trim().split("\\s+");
                for(int j = 0; j < c; j++){
                  matrix[i][j] = Integer.parseInt(str[k]);
                  k++;
                }
            }
            new Solution().booleanMatrix(matrix);
            StringBuilder sb = new StringBuilder();
            for(int i = 0; i < r; i++){
                for(int j = 0; j < c; j++){
                    sb.append(matrix[i][j] + " ");
                }
                sb.append("\n"); 
            }
            System.out.print(sb);
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution
{
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    
     public static int[][] makeRowCol_1(int[][] matrix,int i,int j,boolean[] row, boolean[] col)
    {
        if (!row[i])
        for (int m =0 ;m<matrix[0].length;m++){
            if (matrix[i][m]==0)
                matrix[i][m]=-1;
        }

        if (!col[j])
        for (int n = 0 ;n<matrix.length;n++)
        {
            if (matrix[n][j]==0)
                matrix[n][j]=-1;
        }

        return matrix;
    }
    void booleanMatrix(int matrix[][])
    {
        int[][] ans = new int[matrix.length][matrix[0].length];
        boolean[] row = new boolean[matrix.length];
        boolean[]col = new boolean[matrix[0].length];

        for (int i =0;i<matrix.length;i++)
            for (int j=0;j<matrix[0].length;j++)
            {
                if (matrix[i][j]==1)
                {
                    matrix = makeRowCol_1(matrix,i,j,row,col);
                    row[i]=true;
                    col[j]=true;
                }
            }

        for (int i =0;i<matrix.length;i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                if (matrix[i][j] == -1)
                    matrix[i][j] = 1;

                
            }
             
        }

            //System.out.println();
    }
  
  //https://practice.geeksforgeeks.org/problems/boolean-matrix-problem-1587115620/1/#
    
}
