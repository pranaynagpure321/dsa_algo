class Solution {
public:

  int count =0;

    bool swap(int i , int j , vector<int> & nums)
    {
    
        int l = nums[i];
        int r = nums[j];
        nums[i] =r;
        nums[j] = l;
    
        if(nums[i]%(i+1)==0 || (i+1)%nums[i]==0)             //imp  condition if index and elemnt does not match
            return true;
        
        return false;

        
    }
    void backtrack(int n , vector<int> nums, int first)
    {
        if(first == n)
            count++;


        for(int i = first ; i<n ;i++)
        {
             bool isvalid =   swap(first,i, nums);
               
             if(isvalid)                                // dont backtrack if condition is not valid
               backtrack(n, nums, first+1);
               swap(first,i,nums);
            
        }
    }

    int countArrangement(int n) {

        vector<int> num;

        for(int i =1 ;i<= n ;i++)
            num.push_back(i);

           count =0;
      
        backtrack(n,num,0);
      
        
        //time O(n!) pretty high complexity

        return count;
    }
};
