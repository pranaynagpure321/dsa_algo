 
 
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
    if(fruits.size() == 1) return 1;   
    if(fruits.size() == 2) return 2;
    int ans=0 ,left = 0 ;

    map<int,int> mp;
    
    int  j=0 , n = fruits.size();

    while (j < n) 
    {
        int a = fruits[j];

        if(mp.count(a) == 0)
        {
            mp.insert({a,1});
        }
        else if(mp.count(a) != 0)
        {
            mp[a] = mp[a] + 1;
        }

        if(mp.size() == 2)
        {
            int winsize = j - left +1 ;
            ans = max(winsize ,ans);
        }


        while (mp.size() > 2)
        {
            int fruit = fruits[left++];
            int value = mp[fruit];

            if(value > 1 ) mp[fruit] = value-1;

           else
           mp.erase(fruit);
        }
        
        j++;

    }
        
    if(ans == 0 && mp.size()< 2 && fruits.size()>2) {

        int fruit = fruits[0];
        ans = mp[fruit];
    }
    
    return ans;
    }
};
