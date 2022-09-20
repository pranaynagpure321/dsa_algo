class Solution {
public:
     int getPivoteIdx(vector<int> &nums)                              // get pivot index
    {
        if(nums.size()<2 || (nums[0] < nums[nums.size()-1] )) return -1;
        int ans = -1, n =nums.size();

        int i =0 , j = n-1;

        while (i <= j) {
            int pivot = (i + j) / 2;
            if (nums[pivot] > nums[pivot + 1])                         // if pivot idx isgreater than next element that means we found it
                return pivot ;
            else {
                if (nums[pivot] < nums[i])                           // else check ends that if less that left end to move left 
                    j = pivot - 1;
                else                                                // else move to right
                    i = pivot + 1;
            }
        }
        return -1;
    }

    int binarSearch(vector<int>& nums, int i , int j ,int target)                          // binary serach 
    {
        if(target > nums[j] || target<nums[i]) return -1;

        while (i<=j)
        {
            int mid= (i+j) >>1;

            if(nums[mid]== target)
                return mid;
            if(nums[mid] > target)
                j = mid-1;
            else
                i = mid+1;
        }

        return -1;
    }
    int search(vector<int>& nums, int target) {
        //find pivot index
        
        //if(nums.size()<2) return nums[0]==target? 0 :-1;
        int pivotIdx = getPivoteIdx(nums);
        
        if(pivotIdx == -1)                                                      //if pivoteidx -1 means array is not rotated
            return binarSearch(nums,0 , nums.size()-1,target);

        if(target >= nums[0] and target <= nums[pivotIdx])                      // search in left half because element in that range
        {
            return binarSearch(nums, 0, pivotIdx,target);
        } 
        
        
        //time O(logn)
        //space O(1)
       return binarSearch(nums,pivotIdx+1,nums.size()-1,target);               //else search in right half

    }
};
