/*42. Trapping Rain Water
Hard
 
Share
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example 1:

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9*/

class Solution {
public:
    int trap(vector<int>& height) {

        int leftmax = -1;
        vector<int> left(height.size());
        for(int i =0 ;i < height.size() ;i++)
        {
            leftmax = max(leftmax, height[i]);                          // create vector with max value from left
            left[i] =leftmax;
        }

        int rightmax = -1;
        vector<int> right (height.size());

        for (int j = height.size()-1 ; j>=0 ;j--)                   // create vector with max value from right
        {
            rightmax = max(height[j],rightmax );
            right[j] = rightmax;
        }

        int ans =0 ;

        for(int i =1 ;i< height.size()-1; i++)                // take min of right and left and subtract the bar length if any present at index
        {
            int minbar = min(right[i],left[i]);

            int t = minbar - height[i];

            if(t>0 )
                ans+=t;
        }
        
        
        //time o(n)
        //space O(n)  two arrays used

        return ans;
    }
};
