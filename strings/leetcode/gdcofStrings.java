class Solution {
     public static String gcdOfStrings(String str1, String str2) {
        String ans = "";
         
         if(str1.charAt(0)!=str2.charAt(0))
             return "";

        if(str1.length()<str2.length() )
            return gcdOfStrings( str2,  str1);

        for(int i =1;i<=str2.length();i++)
        {
            String divisor= str2.substring(0,i);
            String tempAns= "";

            for(int j = 0;j< str1.length() ; j+=i)
            {
                if(j+i>str1.length())
                {
                    tempAns = "";
                    break;
                }
                String temp = str1.substring(j,j+i);
                if(divisor.compareTo(temp)!= 0 )
                {
                    tempAns = "";
                    break;
                }
                else {
                    tempAns = divisor;
                }
            }
            
            if(tempAns.length()!= 0)
            for(int j= 0;j< str2.length() ; j+=i)
            {
                if(j+i>str2.length() )
                {
                    tempAns="";
                    break;
                }
                String temp = str2.substring(j,j+i);
                if(divisor.compareTo(temp)!= 0 )
                {
                    tempAns = "";
                    break;
                }
                else {
                    tempAns = divisor;
                }
            }



            if(tempAns.length()> ans.length())
                ans = tempAns;
            // if(ans.length()!=0 && tempAns.length()==0)
            //     return ans;

        }
        return ans;
    }
}
