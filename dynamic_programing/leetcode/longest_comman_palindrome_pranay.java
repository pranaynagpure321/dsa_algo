public static String longestPalindrome(String s) {

        if(isPalindrom(s))
            return s;
        String s1= reverse(s);
        String ans="";
        for (int i =0;i< s.length();i++)
        {
            String temp="";

            for (int j=0;j<s1.length();j++)
            {
                int m=i;
                int n=j;

                while ( m<s.length() && n<s1.length() && s.charAt(m)==s1.charAt(n) )
                {
                    temp+=s.charAt(m);
                    m+=1;
                    n+=1;

                }

                if(temp.length()> ans.length() )
                {
                    if (isPalindrom(temp))
                    ans=temp;
                }
                temp="";
            }
        }
        return ans;

    }

public static String lcs(String s, String t)
    {
        String ans="";
        for (int i =0;i< s.length();i++)
        {
            String temp="";
            for (int j=0;j<t.length();j++)
            {
                int m=i;
                int n=j;

                while (  m<s.length() && n<t.length() && s.charAt(m)==t.charAt(n) )
                {
                    temp+=s.charAt(m);
                    m+=1;
                    n+=1;

                }

                if(temp.length()> ans.length())
                    ans=temp;
            }
        }
        return ans;
    }
