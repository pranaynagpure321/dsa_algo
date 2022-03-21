import java.lang.*;
import java.io.*;
import java.util.*;
class GFG
 {
	public static void main (String[] args) throws IOException
	 {
	 
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
        int t = Integer.parseInt(br.readLine()); 

        while(t-- > 0){
            int size = Integer.parseInt(br.readLine());
            String[] arrStr = ((String)br.readLine()).split("\\s+");
            int[] arr= new int[size];
            for(int i = 0;i<size;i++){
                arr[i] = Integer.parseInt(arrStr[i]);
            }
            System.out.println(new Solution().minJumps(arr));
        }
	 }
	 
}
// } Driver Code Ends


class Solution{
    static int jumps=Integer.MAX_VALUE;
    static int minJumps(int[] arr){
        // your code here
           jumps=Integer.MAX_VALUE;
           dfs(arr,1,1,1+arr[0],0);
           
           if(jumps == Integer.MAX_VALUE)
           return -1;
          
          return jumps;
    }
    
   

    
    static void dfs(int arr[], int current,int start ,int end,int sumofIndex)
    {
       if(sumofIndex>=arr.length && current<jumps)
        {
            //System.out.println(jumps);
            jumps = current;
            return;
        }

        if(sumofIndex>=arr.length)
            return;

        for(int i =start;i<arr.length && i<=end;i++)
        {
            current +=1;
            sumofIndex += arr[i];
            dfs(arr,current, i+1,i+arr[i],sumofIndex);
            sumofIndex -= arr[i];
            current -=1;
        }
    }
}
