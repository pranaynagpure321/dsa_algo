public class Solution {
    public static double findNthRootOfM(int n, long m) {
    	// Write your code here.
		double root=1,increment=1;;
		
		int dplace=0;
		while( dplace<=7)
		{
			double number=1;
			for(int i =1;i<=n;i++)
			{
				number = number*root; 
			}
				
		    if((m-number)==0 )
			{
				if((m-number)==0)
					return root;
				
				//return root+0.000001;
				return root;
			}
			if(number>m)
			{
				root=root-increment;
				increment = increment/10;
				dplace +=1;
			}
			root = root +increment;
		}

		return root;
    }
	
	
}
