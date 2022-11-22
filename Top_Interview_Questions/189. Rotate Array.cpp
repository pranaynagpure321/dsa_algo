class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        if(k%n == 0) return ;

        k = k%n; 
        int cnt =0;
        int i =0;

       for(int i =0 ;cnt< n; i++)
       {
            int cur = i;
            int prev = nums[i]; 
          do
           {
              int next = (cur+ k)%n;
              int t = nums[next];
              nums[next] = prev;
              prev = t;
              cur  = next;
              cnt++;

           }  while(cur != i );
       }

    }
};
