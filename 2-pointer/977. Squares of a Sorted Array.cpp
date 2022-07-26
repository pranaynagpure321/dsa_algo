vector<int> sortedSquares(vector<int>& nums) {


    for(int i =0 ;i< nums.size() ; i++)
    {
        nums[i] = nums[i] * nums[i];
    } 


    int l=0 , r= nums.size()-1;

    while (l <= r)
    {
        if(nums[l] > nums[r])
        {
            int temp = nums[l];
            nums[l] = nums[r];
            nums[r] = temp;
            r--;
        }

        else
        r--;
    }
    
    return nums;
}

vector<int> sortedSquares_2(vector<int>& nums) //optimized approach
{
    int left =0;
    int right = nums.size() - 1;

    vector<int> result(nums.size());
    for(int i  = nums.size() -1 ;i >=0 ; i--)
    {
        int sq;

        if(abs(nums[left]) < abs(nums[right]))
        {
             sq = nums[right];
            right--;
        }

        else 
        {
          
             sq = nums[left];
            left++;
        }
        result[i] = sq*sq;
    }

    return result;
}

int main()
{
    //ector<int> nums = {-4,-1,0,3,10};

    vector<int> nums ={-7,-3,2,3,11};

    vector<int> resutl=  sortedSquares_2(nums);

    for( int c : resutl)
    cout<<c<<" ";
}
