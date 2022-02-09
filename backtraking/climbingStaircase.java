/* discription
You need to climb a staircase that has n steps, and you decide to get some extra exercise by jumping up the steps. 
You can cover at most k steps in a single jump. Return all the possible sequences of jumps that you could take to climb the staircase, sorted.

Example

For n = 4 and k = 2, the output should be

solution(n, k) =
[[1, 1, 1, 1],
 [1, 1, 2],
 [1, 2, 1],
 [2, 1, 1],
 [2, 2]]
 */

public static  int sum =0;
public static LinkedList<Integer> ll = new LinkedList<>();
public static LinkedList<LinkedList<Integer>> large= new LinkedList<LinkedList<Integer>>();
public static int[][] ans ;

int[][] solution(int n, int k) {
   
   if(n==0) return new int[1][0];
    int[] arr =new int[n];
    backtrack(n,0,k);
    ans = new int[large.size()][];
    convertList();
    return ans;
}
public static void convertList()
{
    int i=0;
    for ( LinkedList l1: large) {
        ans[i] = new int[l1.size()];
        for (int j=0;j< l1.size();j++ )
        {
            ans[i][j]=(int)l1.get(j);
        }
        i++;
    }
    large.clear();
}
public static void backtrack(int n, int k,int m)
{
    if  (n==sum)
    {
        sum -=k;
        PrintArray();
        ll.removeLast();
        return;
    }
    else if(sum>n )
    {
        sum -=k;
        ll.removeLast();
        return;
    }

    for(int i=1 ;i<= m; i++ )
    {
        sum +=i; ll.addLast(i);
        backtrack(n, i,m);
    }
    if(!ll.isEmpty()) {
        sum -= k;
        ll.removeLast();
    }
}

public static void PrintArray() {

    LinkedList<Integer> tempList = new LinkedList<>();
    tempList = (LinkedList) ll.clone();
    large.addLast(tempList);

}
