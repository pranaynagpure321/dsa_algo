import java.util.ArrayList;
import java.util.*;

public class Mobilium {

    //The Least Recently Used (LRU) cache is a cache eviction algorithm that organizes elements in order of use.
    //In LRU, as the name suggests, the element that hasn't been used for the longest time will be evicted from the cache.
    static List<Integer> list = new LinkedList<>();
    static SortedSet<Integer> set = new TreeSet<>();

    static int get(int element)   //6
    {
        if (set.contains(element))
        {
            list.remove((Integer)element);
        }
        else if  (!set.contains(element))
        {
            if(list.size()<5)
            set.add(element);

            else
            {
                int removoele =  list.get(list.size()-1);
                list.remove(list.size()-1);
                set.remove(removoele);
                set.add(element);
            }
        }


        list.add(0,element);
        return element;
    }

    static void print()
    {
        System.out.println("Printitn list");
        for (int i =0;i< list.size();i++)
            System.out.print(list.get(i)+" ");
    }

    public static void main(String[] args) {


        get(2);
        get(3);
        get(5);
        get(7);
        get(8);
        get(9);
        get(3);
        print();



    }
}
