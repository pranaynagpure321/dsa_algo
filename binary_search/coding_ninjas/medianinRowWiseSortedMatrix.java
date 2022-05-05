import java.util.ArrayList;

public class Solution
{
	public static int countsmallerthanmid(ArrayList<Integer> list, int key){
		
		int count=0;
		
		for(Integer a : list)
		{
			if(a<=key)
				count+=1;
		}
		return count;
		
	}
	public static int getMedian(ArrayList<ArrayList<Integer>> matrix)
	{
		// Write your code here.
		int row= matrix.size();
		int col=matrix.get(0).size();
		
		int min= Integer.MAX_VALUE;
		int max = Integer.MIN_VALUE;
		for(int i =0;i<matrix.size();i++)
		{
			
			ArrayList<Integer> ll = matrix.get(i);
			if(ll.get(0)<min)
				min= ll.get(0);
			if(ll.get(col-1)>max)
				max= ll.get(col-1);
		}
		
		
		while(min<max)
		{
			int mid = (min+max)/2;
			int get =0;
			
			for(int i =0;i<row; i++)
			{
				ArrayList<Integer> ll = matrix.get(i);
				get += countsmallerthanmid(ll,mid);
			}
			
			if(get<=(row*col)/2)
			{
				min = mid +1;
			}
			else
			{
				max = mid;
			}
		}
		
		
		return min;
	}
}
