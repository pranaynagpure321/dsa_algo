class Solution {
    public List<List<Integer>> generate(int n) {
        // surprizingly this is dp using previous rows as basis for new row
        int k =1;
        List<List<Integer>>  list = new ArrayList< >();
        var prev = new ArrayList<Integer>();
        prev.add(1);
        list.add(prev);
        while(k<n)
        {
            var tmp = new ArrayList<Integer>();
            tmp.add(1);
            
            for(int i =1 ;i<k;i++)
            {
               tmp.add(prev.get(i)+ prev.get(i-1));
            }
            
            tmp.add(1);
            list.add(tmp);
            prev = tmp;
            k++;
        }
        
        // time O(N^2) number of row squars
        return list;
    }
}
