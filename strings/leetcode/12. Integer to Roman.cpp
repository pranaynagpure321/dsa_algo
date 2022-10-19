class Solution {
public:
    string intToRoman(int num) {
        
        map<int, string> regular={{1,"I"},{5,"V"},{10,"X"},{50,"L"},{100,"C"},{500,"D"},{1000,"M"} ,{4,"IV"},{9,"IX"},{40,"XL"},{90,"XC"},{400,"CD"},{900,"CM"}};
        
        vector<int> values = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };

        string ans = "";
        int i = 0;
        while (num>0 and i<13)
        {
            int curDivisor = values[i];
            int a = num / curDivisor;
         
            while (a > 0)
            {
                ans += regular[curDivisor];
                num = num % curDivisor;
                a--;
            }
              
            i++;
        }
        //time is O(1)
        return ans;

    }
};
