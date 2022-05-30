class Solution {
     public static String longest="";
    public String longestPalindrome(String s) {
      
         if (s == null || s.length() < 1) return "";
        int ans=0;
        int [][] dp =new int[s.length()+1][s.length()+1];

        for (int i=0; i<dp.length; i++ )
        {
            for (int j=0; j<dp[0].length; j++ )
                dp[i][j]=-1;
        }
        int start_index=0;
        int max_len=0;
        for (int i=0;i<s.length();i++ )
        {
            //even
           for(int j=i+1;j< s.length();j++)
           {
               if(s.charAt(i)==s.charAt(j) && help(s,i,j,dp)>0)
               {
                   if(j-i>max_len) {
                       max_len = j - i;
                       start_index=i;
                   }
               }
           }
           
        }
        return s.substring(start_index,start_index+max_len+1);

        
    }
       public static int help(String s, int i , int j,int dp[][])
    {
        if(dp[i][j]!=-1)
            return dp[i][j];
        dp[i][j]=0;

        if (Math.abs(i-j)==0)
            return dp[i][j]=1;
        else if(i+1<s.length() && j-1>=0 && s.charAt(i+1)==s.charAt(j-1))
        {
            if(i+1>j-1)
                return dp[i][j]=1;

            dp[i][j] += help(s,i+1,j-1,dp);
        }

        return dp[i][j];

    }
    
   
}
