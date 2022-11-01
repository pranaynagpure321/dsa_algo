class Solution {
public:
  //circular array problem just extend array to twice length
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> res(nums.size(),-1);
        int n = nums.size();
        for (int i =2* nums.size() -1 ; i >=0 ; i--)
        {
            int a = nums[i%n];

            while (!st.empty() and nums[st.top()] <= a) { st.pop(); }

            res[i % n] = st.empty() == true ? -1 : nums[st.top()];

            st.push(i%n);
        }
         

        return res;
    }
};
