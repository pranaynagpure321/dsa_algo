class Solution {

    int binarySearch(List<Integer> list, int target)
    {
       int low = 0, high = list.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (list.get(mid) >= target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
    public List<Integer> countSmaller(int[] nums) {
    
        List<Integer> sort = new ArrayList<Integer>();
        Integer[] tmp = new Integer[nums.length];
        for(int i = nums.length-1; i>=0 ;i--)
        {
            int index = binarySearch(sort,nums[i]);
           // res.add(0,index);

            tmp[i] = index;
            sort.add(index,nums[i]);
        }

        return Arrays.asList(tmp);
    }
}
