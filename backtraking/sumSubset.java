/*Given a sorted array of integers arr and an integer num, find all possible unique subsets of arr that add up to num. Both the array of subsets and the subsets themselves should be sorted in lexicographical order.

Example

For arr = [1, 2, 3, 4, 5] and num = 5, the output should be
solution(arr, num) = [[1, 4], [2, 3], [5]].*/


public static LinkedList<LinkedList<Integer>> ll = new LinkedList<LinkedList<Integer>>();
static int initial = 0;
static int current = 0;
int[][] solution(int[] arr, int num) {

  boolean[] visited = new boolean[arr.length];
  //boolean[] alradyCalculated = new boolean[arr.length];
  backtrack(arr, visited, num,0);
  int[][] finalans= new int [ll.size()][];
  int i=0;
  for( List l1 : ll)
    {
        finalans[i] = new int[l1.size()];
        for(int j=0;j<l1.size();j++)
        {

            finalans[i][j]=(int)l1.get(j);

        }
        i++;
    }
        ll.clear();
  
  return finalans;
}
public static void backtrack(int[] arr,boolean[] visited, int num,int position)
{
    if(num==0)
    {
        addToList(visited,arr); 
     return;
    }
    if(num<0)
    {
        return;
    }
    
    for(int i=position;i<arr.length;i++)
    {
        if(visited[i]==false)
        {
            
            visited[i]=true;
            backtrack(arr, visited, num-arr[i],i+1);
            visited[i]=false;
        }
    }
}
  public static void addToList(boolean [] visited,int[] arr)
    {
        LinkedList<Integer> l1= new LinkedList<>();
        for(int i = 0 ; i<visited.length  ; i++)
        {
            if(visited[i]==true)
                l1.add(arr[i]);
        }
        
        for(LinkedList temp : ll)
        {
            if(l1.equals(temp))
            return;
        }
    
        ll.add(l1);
    }
