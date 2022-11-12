class Solution {
    public long binarySearch(List<Integer> l1, int t)
    { int i =0 ,j =l1.size();

        while (i<j)
        {
            int mid = (i+j)>>1;

            if(l1.get(mid)<= t)
                i = mid+1;
            else
                j= mid;
        }

        return (long)i;
    }

    public long numberOfPairs(int[] nums1, int[] nums2, int diff) {

        long ans =0;

       List<Integer> list = new ArrayList<>();

        for (int j = 0; j < nums1.length; j++) {

            int cur = nums1[j] - nums2[j];
            int target = cur +diff;

            ans  += binarySearch(list,target);

            int idx = (int)binarySearch(list,cur);

            list.add(idx,cur);

        }

        return ans;

    }
}
