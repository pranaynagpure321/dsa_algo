import java.util.Arrays;
import java.util.*;
import java.util.LinkedList;
import java.util.List;

public class Qualcomm {
    public static String minWindow(String s, String t) {
        HashMap<Character,Integer> map = new HashMap<>();
        for(int i = 0; i < t.length(); i++){
            map.put(t.charAt(i),map.getOrDefault(t.charAt(i),0)+1);
        }

        int i = 0;
        int j = 0;
        int count = map.size();
        int minimumI = 0;
        int minimumJ = 0;
        int minimum = Integer.MAX_VALUE;

        while(j < s.length()) {
            if (map.containsKey(s.charAt(j))) {
                map.put(s.charAt(j), map.get(s.charAt(j)) - 1);
                if (map.get(s.charAt(j)) == 0) {
                    count--;
                }
            }

            if (count > 0) {
                j++;
            }

            else{
                while (count == 0) {
                    if (minimum > j - i + 1) {
                        minimum = j - i + 1;
                        minimumI = i;

                        minimumJ = j + 1;
                    }
                    if(map.containsKey(s.charAt(i))){
                        map.put(s.charAt(i), map.get(s.charAt(i)) + 1);
                        if(map.get(s.charAt(i))== 1){
                            count++;
                        }
                    }
                    i++;
                }
                j++;
            }
        }
        return s.substring(minimumI,minimumJ);
    }

    public static int shortestSubstring(String givenString) {



       HashMap<Character, Integer> h1 = new HashMap<>();
       String s = "";
        for (Character c : givenString.toCharArray())
        {
           if (!h1.containsKey(c))
           {
               h1.put(c,1);
               s+= c;
           }
        }

        return  minWindow(givenString,s).length();

    }

    static boolean checksubstring(String s,char[] arr)
    {
        for (int i =0;i< arr.length;i++)
        {
            if (!s.contains(arr[i]+""))
            {
                return false;
            }
        }

        return true;
    }

   static long gMax =0;

    static  void globlaMax(int data[], int r )
    {
        int currmin = Integer.MAX_VALUE;
        for (int i =0 ;i<r ;i++)
        {
            for (int j =i+1 ;j<r ;j++)
            {
                int absdiff = Math.abs(data[i]-data[j]);
                if (absdiff<currmin)
                {
                    currmin = absdiff;
                }
            }
        }

        if (currmin>gMax)
            gMax = currmin;
    }

    static void combinationUtil(List<Integer> arr, int n, int r,
                                int index, int data[], int i)
    {

        if (index == r) {

            globlaMax(data,r);
            return;
        }

        if (i >= n)
            return;

        data[index] = arr.get(i);
        combinationUtil(arr, n, r, index + 1,
                data, i + 1);


        combinationUtil(arr, n, r, index, data, i + 1);
    }

    static void printCombination(List<Integer> arr, int n, int r)
    {

    }
    public static long findMaximum(List<Integer> arr, int m) {

        int data[] = new int[m];
        gMax =0;
        combinationUtil(arr, arr.size(), m, 0, data, 0);

        return gMax;
    }

    public static void main(String[] args) {

       // System.out.println(shortestSubstring("dabbcabcd"));

        List<Integer> l1 = new LinkedList<>(Arrays.asList(1,2,3,4));

        System.out.println(findMaximum(l1,3));

    }
}
