class Solution {
    public void rotate(int[][] matrix) {
          int n = matrix.length;

       // Intuition is do transpose then rever each row

        //transpose : converting evary row to column 
        //notice j looping is only until less than i row

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {

                int tmp  = matrix[i][j];
                matrix[i][j]= matrix[j][i];
                matrix[j][i] = tmp;
            }
            //System.out.println(Arrays.toString(matrix[i]));
        }

         for(int[] a : matrix)
        {
              //System.out.println(Arrays.toString(a));
            for (int i = 0; i < n/2; i++) {
                
                int tmp = a[i];
                a[i] = a[n-i-1];
                a[n-i-1] = tmp;
            }
       }
    }
}
