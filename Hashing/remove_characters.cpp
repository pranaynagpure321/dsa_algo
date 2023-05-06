#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int getremovalcount(string s , string t)
{
   map<char,int> t_map, s_map;

    for(char &c : s) s_map[c]++;
    for(char &c : t) t_map[c]++;
    int res = s.size();

    for( char &ch : t)
    { 
      int cnt = t_map[ch];
      if(!s_map.count(ch)) return 0;

      int source_cnt = s_map[ch];

      res = min(res, source_cnt/cnt);
           
    }

  return res == s.size()? 0 : res;
}
//need to remove all the rearrnged subsequnces of target string from s string like 
int main(int argc, char const *argv[])
{
   string s = "mononom" , t = "abca";
   strign s = "abcbbac" , t = "abc"; //in this exmple abc can be removed twice from source string
  cout<<getremovalcount(s,t);
	return 0;
}
