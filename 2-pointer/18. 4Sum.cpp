
/*Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.
Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]*/

#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

#define mod 1000000007
typedef long long ll;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    
        int n = nums.size();
        sort(nums.begin() , nums.end());
        vector<vector<int>> ans;
        if(n<3 ) return ans;
        
        if(n >= 4  and nums[0] > 0 and nums[0] > target) return ans;
        
        for(int a =0 ; a<n-3 ; a++)
        {
            if(a==0 || (a>0 and nums[a] != nums[a-1] ) )
            for(int b = a+1; b < n-2 ; b++)
            {

                if(b==a+1 || (b>a+1 and  nums[b] != nums[b-1]))
                {
                    int lo = b+1, hi = n-1;
                    while(lo < hi)
                    {
                        ll  sum = (ll)nums[a] + (ll)nums[b] + (ll)nums[lo] + (ll)nums[hi];
                        
                        if(sum == target ) { 
                        
                        ans.push_back({nums[a],nums[b],nums[lo],nums[hi]});
                            lo++; hi--;
                            
                            while(lo<hi and nums[lo] == nums[lo-1]) lo++;
                            while( lo< hi and nums[hi] == nums[hi+1]) hi--;
                        }
                                    
                        else if(sum> target)
                        {
                            hi--;
                        } 
                        
                        else lo++;
                    }
                }
                
            }
        }
        return ans;
}
int main()
{
        // vector<int> v = {2,2,2,2,2};
        // int t = 8;

        vector<int> v = {0, 0, 0, 1000000000, 1000000000, 1000000000, 1000000000};
         int t = 1000000000;
        vector<vector<int>> ans = fourSum(v,t);

        //cout<<(1000000000+1000000000)%1000000007<<endl;
        
        for(auto vec : ans)
        {   for(int a : vec)
            {
                cout<<a<<" ";
            }

            cout<<endl;
        }
}
