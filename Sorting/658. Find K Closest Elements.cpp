class cmp
{
    int xp;
    public:
    cmp(int x) { xp=x;}
    bool operator()(int p1 , int p2){
         if(abs(p1-xp) == abs(p2-xp))
             return p1<p2;
         return abs(p1-xp) <abs(p2-xp);
    }
};

class Solution {
public:
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        sort(arr.begin(), arr.end(), cmp(x));
        arr.resize(k);
        sort(arr.begin(), arr.end());
        return arr;
    }
};
