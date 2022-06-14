
class printnumbers implements  Runnable
{

    int n;
    printnumbers(int n)
    {
        this.n=n;
    }

    public void run( )
    {

        for (int i = 1;i<n ;i++)
        {
            System.out.print(i+" ");
            try{  Thread.sleep(1000);} catch (Exception e){}
        }

    }
}
class hello implements  Runnable
{
    int n;
    hello(int n)
    {
        this.n=n;
    }


    public void run()
    {

        for (int i = 1;i<n ;i++)
        {
            System.out.print(" hi ");
          try{  Thread.sleep(1000);} catch (Exception e){}
        }

    }
}


public class Lenskart   {

    public static int powFuntion(int a ,int b)
    {
        if (b<=0)
        {
            return 1;
        }

        if (b==1)
            return a;

        if (b%2==0)
        return powFuntion(a,b/2)*powFuntion(a,b/2);

        return a* powFuntion(a,b/2)*powFuntion(a,b/2);

    }


    public static void main(String[] args) {


        System.out.println("Thread 1");

       int ans=  powFuntion(2,5);

        System.out.println(ans);


        printnumbers obj1 = new printnumbers(5);
        hello obj2 = new hello(5);

        Thread t1 =new Thread(obj1);
        Thread t2 =new Thread(obj2);

        t1.start();
        t2.start();

    }
}


