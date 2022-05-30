class Solution {
    static List<String> l1= new LinkedList<>();
    public List<String> generateParenthesis(int n) {
        
         l1.clear();
        
        if(n==0 || n< 0) return l1;
        
       
        help(n,n,"");
        return l1;
    }
    
    public static void help(int m , int n,String s)
    {
        if (m==0 & n==0)
        {
            l1.add(s);
        }
        if(m<0  || n<0 )
        {
            return;
        }


        if(m<=n) {
            help(m - 1, n, s + "(");
            help(m, n - 1, s + ")");
        }
    }
}
