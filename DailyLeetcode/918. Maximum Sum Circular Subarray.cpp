class Solution {
public:

    /*
        1. Calulate min subarray sum
        2. calculate  max_array sum
        3. calutlate total
        4. return max of total-min array sum if total no equal to min_array sum;
        5. if total == min_array then return max_array
     */
    int maxSubarraySumCircular(vector<int>& nums) {
        
       int temp1 = 0, total =0, min_sum = nums[0];
       int temp2 =0 , max_sum =nums[0];

       for(int i =0 ;i<nums.size(); ++i)
       {
           temp1 +=nums[i]; temp2 +=nums[i];
           total += nums[i];

            if(temp1 < min_sum) min_sum = temp1;            
            if(temp1 > 0) temp1 = 0;
 
            if(temp2 > max_sum) max_sum = temp2;
            if(temp2 < 0) temp2 =0;
       }
       if(total == min_sum)
       return max_sum;

       return  max( max_sum,total - min_sum);

    }
};
