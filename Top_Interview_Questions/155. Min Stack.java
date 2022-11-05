class MinStack {

    ArrayList<int[]> arr ;
    int minVal ;
    
    public MinStack() {
        arr =  new ArrayList<>();
        minVal = Integer.MAX_VALUE;
    }
   
    public void push(int val) {

        minVal = Math.min(minVal,val);
        int[] a = new int[2];
        a[0] = val;
        a[1] = minVal;
        arr.add(a);

    }
    public void pop() {
       arr.remove(arr.size()-1);
       minVal = arr.size()>0 ? arr.get(arr.size()-1)[1] : Integer.MAX_VALUE;
    }

    public int top() {
       return arr.get(arr.size()-1)[0];
    }

    public int getMin() {
        
        return minVal;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
