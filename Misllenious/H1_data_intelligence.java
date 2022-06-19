import java.lang.reflect.Array;
import java.util.*;

public class H1_Data_Intelligence {



    static int[] getCount(String str)
    {
        int [] arr = new int[26];

        for (char c : str.toCharArray())
        {
            arr[c-'a'] +=1;
        }

        return arr;
    }

    static boolean compare(int[] l1, int[]l2 )
    {
        for (int i =0;i<26;i++)
        {
            if (l1[i]!=l2[i])
                return false;
        }

        return true;
    }

    public static List<String> funWithAnagrams(List<String> text) {

        LinkedList<String> secodlist= new LinkedList<>();

        for (String s : text)
        {
            secodlist.add(s);
        }

        for (int i = 0;i<text.size();i++)
        {
            String str1 =  text.get(i);
            int[] count = getCount(str1);

            for (int j =i+1;j<text.size();j++)
            {

                String str2 = text.get(j);

                if (str2.length()!= str1.length()) continue;

                int[] arr = getCount(str2);

                if (compare(count,arr))
                    secodlist.remove(str2);
            }
        }


        Collections.sort(secodlist);

     return secodlist;
    }



    static int[] coutChars(char[] arr)
    {

        int[] count = new int[5];

        for (char c : arr)
        {
            if (c=='b')
                count[0]++;
            else if (c=='c')
                count[1]++;
            else if (c=='m')
                count[2]++;
            else if (c=='p')
                count[3]++;
            else if (c=='z')
            count[4]++;

            else{ return  new int[0]; }


        }

        return count;

    }

    public static int perfectTeam(String skills) {

        if (skills.length()<5)
            return 0;

        char[] arr =   skills.toCharArray() ;

        Arrays.sort(arr);

        int[] count = coutChars(arr);
        int min = count[0];
        for (int i =1;i<5 ;i++)
        {
            if (min>count[i])
                min = count[i];

        }

        return min;

    }


     static LinkedList<LinkedList<Integer>> adj =new LinkedList<LinkedList<>>();


    static void add(int u,int v)
    {
        adj.get(u).add(v);
        adj.get(v).add(u);
    }

    static void removeAnagrams(String arr[], int N)
    {
        // vector to store the final result
        Vector<String> ans = new Vector<String>();

        // data structure to keep a mark
        // of the previously occurred String
        HashSet<String> found = new HashSet<String> ();

        for (int i = 0; i < N; i++) {

            String word = arr[i];

            // Sort the characters
            // of the current String
            word = sort(word);

            // Check if current String is not
            // present inside the hashmap
            // Then push it in the resultant vector
            // and insert it in the hashmap
            if (!found.contains(word)) {

                ans.add(arr[i]);
                found.add(word);
            }
        }

        // Sort the resultant vector of Strings
        Collections.sort(ans);

        // Print the required array
        for (int i = 0; i < ans.size(); ++i) {
            System.out.print(ans.get(i)+ " ");
        }
    }
    static String sort(String inputString)
    {
        // convert input string to char array
        char tempArray[] = inputString.toCharArray();

        // sort tempArray
        Arrays.sort(tempArray);

        // return new sorted string
        return new String(tempArray);
    }
    public static List<String> classifyEdges(int gNodes, List<Integer> gFrom, List<Integer> gTo, List<Integer> gWeight) {

        ///find all the shortest path

        adj.get(0).add(0);

        for(int i =0;i<gFrom.size();i++)
        {
            add(gFrom.get(i),gTo.get(i));
        }

        Set<String> set = new HashSet<>();
        List<Integer> start = adj.get(1);
        List<Integer> end = adj.get(gNodes);

        int minPath=Integer.MAX_VALUE;
        int temp =0;
        for (int st : start)
        {



        }




    }


    public static void main(String[] args) {


        //int[] arr = getCount("code");

//        List<String> l1 = new LinkedList<>(Arrays.asList("poke",
//                "pkoe",
//                "okpe",
//                "ekop"));
//        System.out.println(Arrays.toString(funWithAnagrams(l1).toArray()));
       // System.out.println(Arrays.toString(arr));

        System.out.println(perfectTeam("pcmbz pcmz pcmb"));




    }
}
