class Solution {
public:
      int add(vector<int>& nums, int cnt , int idx,int a)
    {
        while (cnt)
        {
            nums[idx++] = a;
            cnt--;
        }

        return idx;
    }

    void sortColors(vector<int>& nums) {
        int zeros = 0, ones = 0, twos = 0;

        for (int& a : nums)
        {
            if (a == 0) zeros++;
            else if (a == 1) ones++;

            else
                twos++;
        }


        int i = 0;

        i = add(nums, zeros, i, 0);
        i= add(nums, ones, i, 1);
        add(nums, twos, i, 2);
    }
    
    /* dutch national flag algo
    void sortColors(vector<int>& nums) {
     // for all idx < p0 : nums[idx < p0] = 0
     // curr is an index of element under consideration
    int p0 = 0, curr = 0;
      // for all idx > p2 : nums[idx > p2] = 2
    int p2 = nums.size() - 1;

    while (curr <= p2) {
      if (nums[curr] == 0) {
        swap(nums[curr++], nums[p0++]);
      }
      else if (nums[curr] == 2) {
        swap(nums[curr], nums[p2--]);
      }
      else curr++;
    }
  }*/
};
