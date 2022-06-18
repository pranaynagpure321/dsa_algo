public class GoldmanSachs {

    public static String collapseString(String inputString) {

        if (inputString.length()<=0)
            return "";


        String ans ="";

        for (int i =0;i<inputString.length();i++)
        {
            int count =1;
            char c = inputString.charAt(i);
            for (int j =i+1;j<inputString.length();j++)
            {
                if (inputString.charAt(j)!=inputString.charAt(i)){

                    break;}

                else
                count++;
                i++;
            }
            ans+= count+""+c;
        }


        return ans;

    }



    static String ans ="";
    public static boolean Encoding(String msg, String Key)
    {
        //String ans = "";
        int i=0,j=0;

        while (i<msg.length() && j<Key.length())
        {
            int n=0;
            try {
                n = Integer.parseInt(Key.charAt(j) + "");
            }
            catch (Exception e)
            {
                return false;
            }
            char c = msg.charAt(i);

            if (n<0)
                return false;

            for(int m =0;m<n;m++)
                ans  = ans+ ""+ c;
            i++;j++;
        }

           if (i<msg.length())
               ans += msg.substring(i,msg.length());

           return true;
    }

    public static boolean Decoding(String msg, String Key)
    {

        int i=0,j=0;

        while (i<msg.length() && j<Key.length())
        {
            int n=0;
            try {
                  n = Integer.parseInt(Key.charAt(j) + "");
            }
            catch (Exception e)
            {
                return false;
            }
            char c = msg.charAt(i);
            int count=1;
            int m = i +1;

            for (;m<msg.length();m++)
            {
                if (c!=msg.charAt(m))
                    break;

                count++;
                i++;
            }

            if (count!=n)
                return false;
            else
                ans += c;
            i++;j++;

        }

        if (i<msg.length())
            ans += msg.substring(i,msg.length());

        return true;
    }


    public static String secureChannel(int operation, String message, String key) {

        ans ="";
        if(message.length()<=0)
            return "-1";
        if (operation==1 && Encoding(message,key))
         return ans;

        else if (operation==2 && Decoding(message,key))
            return ans;

        return "-1";
    }



    public static void main(String[] args) {


       // System.out.println(collapseString("AAAA"));

        System.out.println(secureChannel(1,"open","a23"));

    }
}
