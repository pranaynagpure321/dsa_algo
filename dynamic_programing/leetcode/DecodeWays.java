public class DecodeWays {

    static int ways=0;

    static void    help(int i, String s)
    {
        if (i>=s.length())
        {
            ways++;

            return ;
        }
       int number =0;

        if (i+1<=s.length())
        {
            number = Integer.parseInt(s.charAt(i)+"");

            if (number>0)
                help(i+1,s);

            if (number<=0)
                return;

        }
        number =0;
        if (i+2<=s.length())
        {
            number = Integer.parseInt(s.substring(i,i+2));

            if ((number>0 &&  number<10)  || number>26)
                return;

            if (number>0 && number<=26)
                 help(i+2,s);
        }

    }

    public static int numDecodings(String s) {

        help(0,s);

        return ways;
    }


    public static void main(String[] args) {


        System.out.println(numDecodings("226"));
    }
}
