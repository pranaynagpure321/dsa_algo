#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int findComSum(vector<int> &v,int k)
{
  map<int,int> mp;
  int i =0 ,res =-1,sum =0;

  for(int j =0 ;j< v.size(); ++j)
    {
         sum += v[j];
         mp[v[j]]++;

        while( (mp[v[j]]>1 and i<=j) || mp.size()> k  )
          {
            sum -= v[i];
            
            if(mp[v[i]] == 1)
              mp.erase(v[i]);
            else
              mp[v[i]]--;
            i++;
          }
        
        if(mp.size() == k)
       res = max(res, sum);

      //cout<<"sum => "<<sum<<" size=> "<< mp.size()<<endl;
    }
  return res;
}

int main(int argc, char const *argv[])
{
  //vector<int> v = {1,2,7,7,4,3,6};
  vector<int> v = {1,1,1,1,1,1,1,1};
  cout<<findComSum(v,3);

  
//	return 0;
}
