 class Solution {
    public String removeDigit(String number, char digit) {
        
        
        String ans= "";
        int n = number.length();
        for(int i = 0;i< n ; i++)
        {
              if (number.charAt(i) == digit )
              {
                  String temp = number.substring(0,i) ;
                      
                  if(i+1<n)
                    temp += number.substring(i+1,n);
            
                   
                  if(temp.compareTo(ans)>0)
                      ans =temp;
                  
              }
        }
        
        
        return ans;
    }
}
