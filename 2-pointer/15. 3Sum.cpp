#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;



vector<vector<int>> threeSum(vector<int>& nums) { //my brute force
        
    int n = nums.size();
    sort(nums.begin(), nums.end());
    set<vector<int>> ans;

    unordered_map<int,int> mp;

    for(int i =0 ; i < n ; i++)
    {
        mp[nums[i]]++;
        //cout<<nums[i] <<" " <<mp[nums[i]]<<endl;
    }
    
    int L = 0 , R = n-1;
    
    for(int i = 0; i< n ;i++)
    {
        for(int j = i+1 ; j< n ; j++)
        {
            int target = nums[i] + nums[j];

            target = -1* target;

            if(mp.find(target) != mp.end())
            {

                if((target == nums[i] || target == nums[j]) and mp[target] <= 1 )
                continue;

                if((target == nums[i] and target == nums[j]) and mp[target] <= 2 ) continue;

                vector<int> a(3,0);
                a[0]= target; a[1] = nums[i]; a[2]=nums[j];
                sort(a.begin(), a.end());

                ans.insert(a);

                //cout<<target << " "<< nums[i] << " "<< nums[j]<<endl; 
            }
        }
    }

    vector<vector<int> > ans2;
    for(auto m : ans)
    ans2.push_back(m);

return ans2;
    
}


void twoSum (vector<int>& nums, int i  ,vector<vector<int>>& res)
{
   
    int n = nums.size();
    vector<int> ans;

    unordered_set<int> seen;

    for(int j =  i +1 ; j< n ; j++)
    {
        int comple = nums[i] + nums[j];
        comple = -1*comple;

        if(seen.count(comple))
        {
            res.push_back({nums[i], comple , nums[j]});

            cout<<nums[i]<<" "<<comple<<" "<<nums[j]<<endl;

            while (j+1 < n and nums[j] == nums[j+1]) ++j;
            
        }

        seen.insert(nums[j]);
    }

    seen.clear();
 
    return ;
}

 vector<vector<int>> threeSum_2(vector<int>& nums) {   //expeacted  approach
 
    sort(nums.begin(), nums.end());

    int n  = nums.size();

    vector<vector<int>> ans;

    for(int i =0 ; i < n && nums[i] <= 0; ++i)
    {
        if (i == 0 || nums[i - 1] != nums[i])
        twoSum(nums,i, ans);
    }
    
    return ans;

 }


vector<vector<int>> threeSum_3(vector<int>& nums) {    //most optimized approach
    vector<vector<int>> ans;
    int n = nums.size();

    int k = 0  , l = k+1, r =n-1;
    
    sort(nums.begin(), nums.end());

    while (k < n-2)
    {

        if(k ==0 || (k>0 and nums[k] != nums[k-1]))
        {
            l = k +1 ; r = n-1;
            int target = -1*nums[k];
            while (l < r)
            {
                if(nums[l] + nums[r] < target)
                l++;

                else if(nums[l] + nums[r] > target)
                r--;

                else
                {
                    ans.push_back({nums[k],nums[l], nums[r]});
                    l++;r--;

                    while ( nums[l-1] == nums[l]) l++;

                    while(nums[r] == nums[r+1]) r--;
                    
                }
            }
        }
            k++;
    }
    return ans;  
}


int main()
{
    vector<int> vec = {-1,0,1,2,-1,-4};
    vector<int> vec2 = {-1,0,1,0};
    vector<int> vec3 = {-1,0,1,2,-1,-4,-2,-3,3,0,4};

    vector<vector<int>> v = threeSum_3(vec3);

    for(auto a : v ){
     for(int val : a)
      cout<<val<<" ";

    cout<<endl;  
    }

}
