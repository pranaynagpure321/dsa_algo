import java.util.*;

public class EpiFi {



    public static int  help2(int m,int n,List<List<Integer>> warehouse,int[][] dp)
    {
        if (m==1 && n==1 && warehouse.get(m-1).get(n-1)==1)
        {
            return 1;
        }
        if(m<1 || n<1)
            return 0;


        if (warehouse.get(m-1).get(n-1)==0)
            return 0;

        if (dp[m][n]!=0)
            return dp[m][n];

        dp[m][n] += help2(m-1,n,warehouse,dp);
        dp[m][n] += help2(m,n-1,warehouse,dp);

        return dp[m][n];

    }


    public static int numPaths(List<List<Integer>> warehouse) {

      //  int[][] obstacleGrid = new int[warehouse.size()][warehouse.get(0).size()];



        if (warehouse.size() < 1)
            return 0;


        int m = warehouse.size();
        int n = warehouse.get(0).size();
        int[][] dp = new int[m + 1][n + 1];
        int ans = help2(m, n, warehouse, dp);

        return ans;

    }


    public static long paperCuttings(int textLength, List<Integer> starting, List<Integer> ending) {


        HashSet<String> set = new HashSet<>();
        int count=0;
        for (int i =0 ;i<starting.size();i++)
        {
            String temp = starting.get(i)+"-"+ending.get(i);

            if (set.contains(temp))
            {
                count--;
            }
            else {
                count++;
                set.add(temp);
            }
        }

        return count;
    }
    public  static long profit(long pickup, long drop, long tip) {

        return (drop-pickup)+tip;
    }

    public static long taxiDriver2(List<Long> pickup, List<Long> drop, List<Integer> tip) {


        int maxProfit=0;

        TreeMap<Integer, Integer> map=new TreeMap<>();
        map.put(0,0);

        long[][] jobs=new long[pickup.size()][3];

        for(int i=0;i<pickup.size();i++){
            jobs[i]=new long[]{pickup.get(i),drop.get(i),tip.get(i)};
        }
        // Sorting with endTime
        Arrays.sort(jobs, (a,b) -> (int)a[1]-(int)b[1]);


//        for(int i=0;i<jobs.length;i++){
//            int p=jobs[i][2]+map.floorEntry(jobs[i][0]).getValue(); // profit on existing job + profit we can get job before start this job
//            if(p>map.lastEntry().getValue()){
//                map.put(jobs[i][1],p);
//            }
//        }

        return map.lastEntry().getValue();
    }


    public static long taxiDriver(List<Long> pickup, List<Long> drop, List<Integer> tip) {

        int n = pickup.size();
        long[][] dp = new long[n][3];

        for(int i =0;i<n;i++) {
            dp[i] = new long[]{pickup.get(i), drop.get(i) , profit(pickup.get(i), drop.get(i),tip.get(i))};
        }

        Arrays.sort(dp,(a,b)->(int)a[1]-(int)b[1]);

        TreeMap<Long, Long> tree = new TreeMap<Long, Long>();
        tree.put(0l, 0l);

        for(long[] del : dp) {
            Long temp = del[2]+ tree.floorEntry(del[0]).getValue();
            if(temp>tree.lastEntry().getValue()) {
                tree.put(del[1], temp);
            }
        }
        return tree.lastEntry().getValue();

    }




    public static void main(String[] args) {


//        List<Integer> l1 = new LinkedList<Integer>(Arrays.asList(1,1,1,1));
//        List<Integer> l2 = new LinkedList<Integer>(Arrays.asList(1,1,1,1));
//        List<Integer> l3 = new LinkedList<Integer>(Arrays.asList(1,1,1,1));
//
//        List<List<Integer>> warehouse = new LinkedList<List<Integer>>();
//
//        warehouse.add(l1);
//        warehouse.add(l2);
//        warehouse.add(l3);


        int text =8;
        List<Integer> starting = new LinkedList<Integer>(Arrays.asList(3, 4, 5, 6, 8));
        List<Integer> ending = new LinkedList<Integer>(Arrays.asList(4, 5, 6, 7, 8));
        long ans = paperCuttings(text,starting,ending);

        System.out.println(ans);

    }
}
