import java.util.ArrayList;
import java.util.Arrays;

public class Heap {

    static ArrayList<Integer> heap = new ArrayList<>();
    static int n =0;

    public static void delete()
    {
        heap.set(1,heap.get(n));
        n--;
        int i=1;

        while (i<n)
        {
            int left =  heap.get( 2*i);
            int right = heap.get(2*i+1);
            int result = left>right? 2*i : 2*i+1;
            if (heap.get(i) < heap.get(result))
            {
                int ele = heap.get(i);
                heap.set(i, heap.get(result));
                heap.set(result,ele);
                i=result;

            }
            else return;
        }

    }

    public static void insert(  int ele)
    {
        if (n<2)
        { heap.add(1,ele); n++; return;}

        heap.add(ele);
        n++;
        int i =n;

        while (i>1)
        {
            int parIndex = i/2;
            int parValue = heap.get(parIndex);

            if (parValue<heap.get(i))
            {
                heap.set(i,parValue);
                heap.set(parIndex,ele);
                i= parIndex;
            }
            else return;
        }
    }
    public static void main(String[] args) {


        heap.add(0,-1);// n++;
//        insert( 50);
//        insert( 30);
//        insert( 40);
//        insert( 10);
//        insert( 5);
//        insert( 20);
//        insert( 30);
//        insert( 60);

        
        System.out.println(Arrays.toString(heap.toArray()));
        delete();


        System.out.println(Arrays.toString(heap.toArray()));


    }
}
