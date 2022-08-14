/*2375. Construct Smallest Number From DI String
User Accepted:5119
User Tried:5739
Total Accepted:5289
Total Submissions:7957
Difficulty:Medium
You are given a 0-indexed string pattern of length n consisting of the characters 'I' meaning increasing and 'D' meaning decreasing.

A 0-indexed string num of length n + 1 is created using the following conditions:

num consists of the digits '1' to '9', where each digit is used at most once.
If pattern[i] == 'I', then num[i] < num[i + 1].
If pattern[i] == 'D', then num[i] > num[i + 1].
Return the lexicographically smallest possible string num that meets the conditions.


string smallestNumber(string pattern) {
        stack<int> s;
        string ans = "";
        if(pattern[0] == 'I') ans += '1';
        else s.push('1');
        for(int i = 1; i <= pattern.size(); i++){
            if(pattern[i-1] == 'I'){
                while(!s.empty()){  ans += s.top(); s.pop(); }
            }
            s.push('0' + i+1);
        }
        while(!s.empty()){ ans += s.top(); s.pop();  }
        return ans;
    }
 */

typedef long long ll;
class Solution {

    ll dfs(string pattern, int i, int prev , string no , vector<bool>& visited)
    {
        if(i > pattern.length())
        {
            //cout<<no<<endl;
            return stoll(no);
        }

        ll ans = LLONG_MAX;

        if(pattern[i-1] == 'I')
        for( int j = prev+1 ; j<= 9 ; j++ )
        {
            ll temp =LLONG_MAX;
            if(!visited[j])
            {
                visited[j] = true;
                temp = dfs(pattern, i+1,j,no+to_string(j), visited);
                visited[j] = false;
            }

            ans = min(ans, temp);
        }

        else
        for( int j = prev-1 ; j >= 1 ; j-- )
        {
            ll temp =LLONG_MAX;
            if(!visited[j])
            {
                visited[j] = true;
                temp = dfs(pattern, i+1,j,no+to_string(j), visited);
                visited[j] = false;
            }
            ans = min(ans, temp);
        }
        return ans;
    }
    public:
    string smallestNumber(string pattern) {  
    ll ans = LLONG_MAX;
    vector<bool> visited (pattern.length()+1,false);
    if(pattern[0] == 'I'){
    
        visited[1] =true;
        ans =   dfs(pattern,1,1,"1",visited);
    }
     else{
        
        for(int i = 9 ; i>=1 ; i--){
         visited[i] =true;
         ans = min(ans, dfs(pattern,1,i,to_string(i),visited));
         visited[i] = false;

        }
     }
     cout<<ans;

     return to_string(ans) ;
    }
};
