#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

#define   mod  1000000007

int help(int n , int state , int dp[][4] )
{

    if(n ==1 || n==0)
    {
        if(state == 0)
        return 1;

        return 0;
    }
    
    if(dp[n][state] != 0) 
        return dp[n][state];
    int ans =0;
    if(state == 0)
    {

        //pick vertical domino
        ans += help(n-1,0,dp)%mod;

        if(ans > mod)
        ans = ans%mod;
        
        //pick horizontal domino
        ans += help(n-2,0,dp)%mod;

        if(ans > mod)
        ans = ans%mod;

        //pick up tormino
        ans +=  help(n-1, 1,dp)%mod;

        if(ans > mod)
        ans = ans%mod;

        //pick down tormino
        ans += help(n-1, 2,dp)%mod;

        if(ans > mod)
        ans = ans%mod;

       
    }

    if(state == 1)
    {
        //hhorizontal down domino
        ans += help(n-1,2,dp)%mod;

        if(ans > mod)
        ans = ans%mod;

        //down tormino
        ans += help(n-2,0,dp)%mod;

        if(ans > mod)
        ans = ans%mod;
    }

    if(state == 2)
    {
        //horizontal up domino
        ans += help(n-1, 1,dp)%mod;

        if(ans > mod)
        ans = ans%mod;

        //up tormino
        ans += help(n-2,0,dp)%mod;

        if(ans > mod)
        ans = ans%mod;
    }

    return dp[n][state]=ans;

}


int numTilings(int n) {
        

    int dp[n+1][4];
    memset(dp, 0, sizeof(dp));
    int ans = help(n,0,dp);

    return ans;
}


//iterative approach
int numTilings_iterative(int n) {

    
    if(n==1) return 1;
    if(n==2) return 2;
    int dp2[n+1];
    memset(dp2, 0, sizeof(dp2));
    dp2[0] = 1;
    dp2[1] = 1;
    dp2[2] = 2;
    dp2[3] = 5;

    for(int k =4 ; k<= n ; k++)
    {
      
        dp2[k] = ((2*dp2[k-1])%mod + dp2[k-3]  % mod )  % mod; 

    }


    return dp2[n];

}

int main()
{
     //n =10  ans 1255;
     //n =5 ans =24;
    cout<<numTilings(100)<<endl;

}
