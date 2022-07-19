class Solution {
public:
    int fillCups(vector<int>& amount) {
        
        int a = amount[0];
    int b = amount[1];
    int c = amount[2];
   
    if(a>b+c) return a;
    if(b>a+c) return b;
    if(c>a+b) return c;
        
    if(a==0) return b>c? b : c;
    if(b==0) return a>c? a : c;
    if(c==0) return a>b? a : b;
        
    
   
    int sum = a+ b+c;

    if(sum%2 > 0) return sum/2 +1;

    return sum/2;
        
        
    }
};
