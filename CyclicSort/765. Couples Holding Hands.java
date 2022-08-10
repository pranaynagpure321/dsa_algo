/* 765. Couples Holding Hands
Hard

1784

90

Add to List

Share
There are n couples sitting in 2n seats arranged in a row and want to hold hands.

The people and seats are represented by an integer array row where row[i] is the ID of the person sitting in the ith seat. The couples are numbered in order, the first couple being (0, 1), the second couple being (2, 3), and so on with the last couple being (2n - 2, 2n - 1).

Return the minimum number of swaps so that every couple is sitting side by side. A swap consists of choosing any two people, then they stand up and switch seats.

 

Example 1:

Input: row = [0,2,1,3]
Output: 1
Explanation: We only need to swap the second (row[1]) and third (row[2]) person.
Example 2:

*/


class Solution {
    
     void swap(int[] row , int i , int j,HashMap<Integer, Integer> map )
     {
         int temp = row[i];    //swap two elemets in array with given position
         row[i] = row[j];
         row[j] = temp;
          
         
         map.put(row[i],i);   //swap those in map as well
         map.put(row[j],j);
     }
    
    
    public int minSwapsCouples(int[] row) {
        
         var map = new HashMap<Integer, Integer>();
        
        
        //put every position on map  value ans index as location
        for(int i =0 ; i< row.length ;i++)
        {
            map.put(row[i] , i);  
        }
        
        int swap =0 ;
        
        
        for(int i =0 ; i< row.length ;i+=2)
        {
            int first  =   row[i];
            int second  = first ^ 1;  //bitwise or to check number is even is its even then incremented else decremented
            
            if(second != row[i+1]) //swap if there is mismatch in second element
            {
                swap++;
                swap(row, i+1, map.get(second), map);   
            }
        }
        
        //time O(nlogn)
        return swap;
    }
}
