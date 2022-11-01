class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp;
        for (int i = 0; i < nums1.size(); ++i)
        {
            mp[nums1[i]] = i; 
        }    // above map is to create number to index mapping

        stack<int> st;
        for (int i = nums2.size() - 1; i >= 0; i--)          // using mono stack by traversing array in reverse
        {
            int a = nums2[i];
            int idx =   mp.count(a) == true ? mp[a] : -1;

            while (!st.empty() and st.top() < a)
            {
                st.pop();
            }

            if(idx != -1)
            nums1[idx] = st.empty() == true ? -1 : st.top();

            st.push(a);
        }

        return nums1;
    }
};
