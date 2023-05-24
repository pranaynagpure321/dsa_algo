class Solution {
public:

/* collect all the R , E , W , Q and interate over string to find the length where all four character has <= n/4 count 

if that is found then take window length and increment left pointer while taking the window size in to account 
*/
    int balancedString(string s) {

    map <char, int> mp;
    int n = s.size();
    int i =0 ,j, res =INT_MAX ;
    
    for(char c : s )
    mp[c]++;

    if( mp['R'] == n/4  and mp['E'] == n/4 and mp['Q'] == n/4 and mp['W'] == n/4 )
    return 0;

    for(j =0 ; j< s.size(); ++j)
    {
      mp[s[j]]--;
      while( i <= j and mp['R'] <= n/4  and mp['E'] <= n/4 and mp['Q'] <= n/4 and mp['W'] <= n/4)
      {
        res = min(res , j-i+1);
        mp[s[i]]++; ++i;
      }

    }  
     return  res;
    }
};
