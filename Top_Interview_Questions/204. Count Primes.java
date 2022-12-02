class Solution {

    void fill(boolean[]arr , int prime)
    {
        if(arr[prime]) return;             // before this optimization beats 14% after this beast 96%
        for(int j = prime*prime ; j<arr.length ;j+=prime)  // fill all the no prime multiple in array
        arr[j] = true;
    }

    public int countPrimes(int n) {
        if(n<=2) return 0;
        if(n == 3) return 1;
        boolean[] arr = new boolean[n];  // create boolean array and make all the non prime elemets true
        int res =0;
        for(int i = 2 ;i <= Math.sqrt(n) ;i++)
        {
            fill(arr,i);
        }

        for(int i=3 ;i<n ;i+=2)             // count all the false in boolean array
        if(!arr[i]) res++;

        return  res +1;
    }
}
