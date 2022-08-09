class Solution {
    public int findKthPositive(int[] arr, int k) {
        
        
        int count =arr[0] - 1;
        
        if(count >= k ) return k;
       
        int ans = 0;
        
        for(int i =1 ; i< arr.length ; i++)
        {
            
            if(arr[i] != arr[i-1] + 1)
            {
                int temp = arr[i] - arr[i-1] -1; 
                
                if(count + temp >= k)
                {
                    ans = arr[i-1] +  k - count;
                    return ans;
                }
                else
                    count +=temp;
            }
        }
        
        if(count < k )
        {
            ans = arr[arr.length-1] + k -count;
        }
       
                
      return ans;
        
    }
}
