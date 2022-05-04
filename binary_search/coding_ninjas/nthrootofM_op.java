public class Solution {
	 public static double multiply(double number, int n) {
        double ans = 1.0;
        for(int i = 1;i<=n;i++) {
            ans = ans * number;
        }
        return ans; 
    }
    public static double findNthRootOfM(int n, long m) {
    	// Write your code here.
	
		double high=m,low=1;
		double eps = 1e-7;
		
		while((high-low)>eps)
		{
			double number=1;
			double mid= (high+low)/2.0;
			
			if(multiply(mid,n)<m)
			{
				low=mid;
			}
			else{
				high=mid;
			}
		}
		

		return low;
    }
	
	
}
