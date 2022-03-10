/*A top secret message containing uppercase letters from 'A' to 'Z' has been encoded as numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
You are an FBI agent and you need to determine the total number of ways that the message can be decoded.

Since the answer could be very large, take it modulo 109 + 7.

Example

For message = "123", the output should be
solution(message) = 3.

"123" can be decoded as "ABC" (1 2 3), "LC" (12 3) or "AW" (1 23), so the total number of ways is 3. */






#include <iostream>
#include<string>
using namespace std;

unsigned long long int  dp[200]; 
unsigned long long int fib(int n )
{
    if(n==1 || n==2)
    return 1;
    
    if(dp[n]!=0)
    return dp[n];
    
    dp[n] = (fib(n-1)+fib(n-2))%1000000007;
    
    return dp[n];
}

int solution(string message) {
    memset(dp,0,sizeof(dp));
    
    if(message.length()<1)
    return 1;
    int ways =1;
    for(int i =0 ;i< message.length();i++)
    {
        if(message[i]=='0')
        return 0;
        
        if(message[i] =='1' || message[i]=='2' )
        {
            int fibno=0;
            for(int j =i ;j< message.length();j++)
            {
                if(message[j]-'0'> 6 && message[j-1]=='2' )
                {
                    i=j;
                    break;
                }
               else if(message[j]-'0'>2 ){
                  i=j;fibno+=1;
                    break;
                }
                else if(message[j]=='0')
                {
                    i=j; fibno -=1;
                    break;
                }
                i=j;
                fibno+=1;
              
            }
            // cout<<fibno;
            ways *= fib(fibno+1);
            
        }
          
        
    }
    
    return ways;

}

int main()
{
   string str="1221112111122221211221221212212212111221222212122221222112122212121212221212122221211112212212211211";
    cout<<solution(str);
}
