// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int i =1 , j =n;
        while( i <=  j)
        {
            int mid =  i + (j-i)/2;
            
            bool flag = isBadVersion(mid);
            if(flag and !isBadVersion(mid-1))
            {
                return mid;
            }
            
            if(flag)
                j = mid -1;
            
            else
                i = mid+1;
            
        }
        
        return 0;
        
    }
};
