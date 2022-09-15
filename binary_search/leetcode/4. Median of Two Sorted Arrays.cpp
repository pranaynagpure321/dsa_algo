class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int n1 =nums1.size(), n2 = nums2.size();
        
        if(n1 > n2) return findMedianSortedArrays(nums2, nums1);       // binary search on small array
        if(n1 ==0 )
        {
            if(n2%2!=0) return  nums2[n2/2];                                 

            else return (nums2[n2/2] + nums2[n2/2 - 1] )/2.0;
        }
       
        int  i = 0, j = n1;
        int R1 = INT_MIN, R2 = INT_MIN;
        int L1 = INT_MAX, L2 = INT_MAX;

        while ( i <= j )
        {
            int cut1 = (i+j)/2;
            int cut2 = ((n1+n2+1)/2) - cut1;

            L1 = (cut1 <= 0 ) ? INT_MIN : nums1[cut1-1];
            L2 = (cut2 <= 0 ) ? INT_MIN : nums2[cut2-1];
            R1 = (cut1 ==  n1) ? INT_MAX : nums1[cut1];
            R2 = (cut2 == n2) ? INT_MAX : nums2[cut2];


            if(L1 <= R2 and L2<= R1)                 //if we found the median point
            {
                if((n1+n2)%2 !=0)
                {
                    return max(L1,L2);
                }

                return (max(L1,L2)+ min(R1,R2))/2.0;
            } 
            if(R1 > L2  )                    //if R1 > L2 or R2 > L1 then go to left
            {
                j = cut1-1;
            } else                           // else go to right
            {
                i = cut1+1;
            }
        }


        return 0.0;
    }
};
