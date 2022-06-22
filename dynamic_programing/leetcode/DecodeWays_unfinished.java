import java.util.Arrays;

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

    static int  help2(int start, String s,int[] dp)
    {
        if (start<=0)
        {
            return 1;
        }
        if (dp[start]!=-1)
            return dp[start];

        int takeone=0,takeTwo=0;

         if (s.charAt(start-1)!='0')
         takeone =  help2(start-1,s,dp);

         if(start>1) {
             int digit = Integer.parseInt(s.substring(start - 2, start));
             if (digit > 9 && digit < 27)
                 takeone +=  help2(start - 2, s,dp);
         }
        return dp[start]= takeone ;
    }

    public static int numDecodings(String s) {

        int[] dp = new int[s.length()+1];
        Arrays.fill(dp,-1);
        return help2(s.length(),s,dp);
    }


    public static void main(String[] args) {


        //System.out.println(numDecodings("226"));
        String s = "111111111111111111111111111111111111111111111";

        System.out.println(numDecodings(s));
    }
}
