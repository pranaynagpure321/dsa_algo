//maximize the output by robbing alternative houses



#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
int dp(vector<int> &nums , int start,int temp, int &max,vector<int> &dparr)
{
    if(dparr[start] != -1){
     return  dparr[start];
    }
    for(int i = start; i<nums.size(); i++)
    {
       
        int subsum =0 ;
        subsum +=nums[start];
        if(i+2> nums.size()-1)
        dparr[i]=nums[i];
        
        else{
         int temp =dp(nums, i+2, subsum, max,dparr)+subsum;
         if(temp>dparr[start])
         dparr[start] = temp;
       
        }
    }
    return dparr[start];
}

int solution(vector<int> nums) {
    
    int max =0;
    vector<int> dparr (nums.size(),-1);
    dp(nums, 0,0,max,dparr);
    dp(nums, 1,0,max,dparr);
    
    for(auto i : dparr)
    {
        if(i> max)
        max=i;
    }
   
    return max;

}

int main()
{
   // printf("Hello World");
    vector<int> vec {1, 2, 1, 1};
    cout<<solution(vec);

    return 0;
}
