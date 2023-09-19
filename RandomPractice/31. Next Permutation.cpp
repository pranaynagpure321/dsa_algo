class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
     //find the break point {1,3,5,4,2}  break point => 5 as its peak of array we need to find a[i] < a[i+1]
    bool flag =false;
    int n =nums.size(), j =n-2;
    for(; j>=0 ;j--)
    {
      if(nums[j+1] > nums[j])
      {
        flag= true;
        break;
      }
    }

    //cout<< " flag =>" <<flag << " breakpoint=> "<<j+1<<endl;

    if(flag)
    {
        //find element just greater than jth element
        int ele = INT_MAX, idx= j+1;
        for( int i = n-1;  i>j ; i--)
        {
           if(nums[i] > nums[j] and ele> nums[i])
           {
             idx = i;
             ele = nums[idx];
           }
        }

        swap(nums[j], nums[idx]);

       sort(nums.begin()+j+1, nums.end());
        return;
    }

    sort(nums.begin(), nums.end());
    }
};
