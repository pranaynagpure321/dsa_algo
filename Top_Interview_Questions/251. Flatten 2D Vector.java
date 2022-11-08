class Vector2D {

    int size;
    int[][] arr;
    int currRow, currCol,curr;

    public Vector2D(int[][] vec) {  
        arr = vec;
        curr =0;
        currRow =0; currCol=0;
        for(int[] v : vec)
        {
            size += v.length;
        }
    }
    
    public int next() {
        
        while(arr[currRow].length ==0 )
        currRow++;
        int res = arr[currRow][currCol];

        currCol = ((currCol+1)>=arr[currRow].length) ? 0: (currCol+1);
        currRow = currCol ==0 ? (currRow+1): currRow;
        curr++;

        return res; 
    }
    
    public boolean hasNext() {
        
        return curr<size;
    }
}

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D obj = new Vector2D(vec);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */
