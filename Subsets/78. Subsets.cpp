/*et S[] = [1,2,3]
Total number of subsets = pow(2, n) = pow(2, 3) = 8

Value of integer           Subsets
    000                    -> Empty set
    001                    -> 1
    010                    -> 2
    011                    -> 12
    100                    -> 3
    101                    -> 13
    110                    -> 23
    111                    -> 123 */


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        int n = nums.size();
        int size = pow(2,n);                //calculate the size of subasets

        vector<vector<int>> ans;
        for(int i =0 ;i <size ;i++)                          //bit mask aprroach
        {
            vector<int> tmp;
            for(int j = 0 ; j<n ;j++)                         //iterate over bits of index i 
            {
                if(i & (1<<j))
                tmp.push_back(nums[j]);                       //if jth bit is set then push that element to vector
            }
            ans.push_back(tmp);                              //push that vector to ans
        }

      return ans;
    }
};
