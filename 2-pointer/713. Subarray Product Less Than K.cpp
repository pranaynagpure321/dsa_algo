#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    
    
    int count  =0;
    int n = nums.size();
    int product =1 , i=0;

    for(int j = 0 ; j< n ; j++)
    {

        product *= nums[j];
 
        while (product >= k)
        {
           product /= nums[i++];
        } 

        count += j - i + 1;
    }
    return count>0 ? count : 0;
}

int main()
{
  vector<int> v = {10,5,2,6};
  int k = 100;
  cout<<numSubarrayProductLessThanK(v , k);
}
