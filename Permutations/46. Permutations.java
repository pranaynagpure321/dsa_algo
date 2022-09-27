class Solution {
    
    static  LinkedList<List<Integer>> out = new LinkedList< >();

    public static void swap(Integer[] arr, int a , int b)
    {
        int t = arr[a];
        arr[a] =arr[b];
        arr[b] =t;
    }
    public static   void help(int n,Integer[] nums)
    {
        if(n==1)
        {
            out.add(Arrays.asList(nums.clone()));
            return;
        }

        for (int i =0 ;i< n;i++)
        {
            help(n-1,nums);
            if(n%2 ==0)
            {
                swap(nums, i,n-1);
            }
            else
                swap(nums,0,n-1);

        }
    }
    public List<List<Integer>> permute(int[] nums) {
        
        out.clear();
        
        Integer[] arr = new Integer[nums.length];


        for (int i = 0; i < arr.length; i++) {

            arr[i] = nums[i];
        }
        help(nums.length, arr);
        out.forEach(System.out::println);
        return out;
        
    }
}
