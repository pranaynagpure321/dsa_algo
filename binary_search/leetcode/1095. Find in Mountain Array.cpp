/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    
     int findPeakIndex( MountainArray &mountainArr )              //find peak element index in array
    {
        int n = mountainArr.length();
        int i =0 , j = n-1;
        while ( i <= j )                                        
        {
            int mid = (i+j)>>1;
            int midele = mountainArr.get(mid);
            int left = mid-1>=0? mountainArr.get(mid-1) : INT_MIN;
            int right = (mid+1)< n ? mountainArr.get(mid+1) : INT_MIN;

            if(mid-1> 0 && mid+1<n && midele > left and midele > right )
            {
                return mid;
            }
            if(mid-1>=0 && left> midele)
                j= mid-1;
            else i= mid+1;
        }

        return i-1;
    }
     int binarySearch(int target, MountainArray &mountainArr, int i , int j, bool isup)           // binary seach on left anf right array
    {
        while (i <= j)
        {
            int mid = (i+j)>>1;

            int midEle = mountainArr.get(mid);

            if(midEle == target)
                return mid;

            if(isup)                                           // thi isUp define search in first half
            {
                if (midEle > target)
                    j = mid - 1;

                else
                    i = mid + 1;
            }
            else                                             // else search in second half
            {
                if(midEle > target)
                    i= mid+1;
                else j =mid-1;
            }
        }
        if(mountainArr.get(i) == target) return i;

        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        
       int peakidx = findPeakIndex(mountainArr);             // find peak index in array
       int n = mountainArr.length();
       
       int peakEle = mountainArr.get(peakidx);             // get the peak element
       int first = mountainArr.get(0);
       int last = mountainArr.get(n-1);
        
        
       if(target < first && target < last) return -1;        //if out of range then return -1;
       if(peakEle == target) return peakidx;
       if(target >= first  && target<= peakEle )               //search in first half of mountain array
       {
           int ans = binarySearch(target, mountainArr , 0, peakidx, true);
           
           if(ans != -1 ) return ans;
       }
        
        // time logn
        //space O(1)
      return  binarySearch(target, mountainArr, peakidx, n, false);           //search in second half of array
    }
};
