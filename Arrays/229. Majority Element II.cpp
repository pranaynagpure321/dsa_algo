
      /*
      
      you will only have 2 elements at max a  time , so we just need to find those two, 
      first will initialize two variables with INT_MIN n1 and n2 then we need to create 2 countrs which whill count frequenncy
      and after then follow code for more info.
      
      */


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int n1 = INT_MIN, n2 = INT_MIN;
        int c1 = 0, c2 = 0;

        for(int i =0 ;i< nums.size() ;i++)
        {
           if(n1 == nums[i])  c1++;
           else if(n2 == nums[i] ) c2++;

           else if(c1 == 0) n1 = nums[i] ,c1 =1;
           else if(c2 == 0) n2 = nums[i] , c2 =1;
           else c1--,c2--;
        } 

        int n = nums.size();
        c1 =0, c2=0;
        for(int ele : nums)
        {
            if(n1 == ele) c1++;
            if(n2 == ele) c2++;
        }
        vector<int> res;
        int maj = n/3;
        if(c1 > maj) res.push_back(n1);

        if( n2 != n1 and c2 > maj ) res.push_back(n2);

        return res;
    }
};
