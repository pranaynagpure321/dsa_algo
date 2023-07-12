/*
Algorithm

    Initialize two integer variables, totalLoad and maxLoad. totalLoad stores the sum of all the elements of weights and maxLoad stores the largest element of weights.
    Create a method feasible which takes weights, c, days as the parameters and returns true if we can ship all the packages with c capacity.
    Perform binary search over the range maxLoad to totalLoad.
        Create two variables, l and r, to represent the beginning and end of the range. Set l = maxLoad and r = totalLoad. We can always ship all the weights within days days with r capacity.
    Then, while l < r:
        Find the midpoint of the range (l, r) in the variable mid = (l + r) / 2.
        Call feasible(weights, mid, days) to see if we can ship all the weights in days days while using mid as the ship's capacity.
        If we can ship the packages with mid as ship's capacity in less than or equal to days days, we move to lower half of the range by setting r = mid.
        Otherwise, if we cannot ship the packages with m capacity in required days, we move to upper half of the range by setting l = mid + 1.
    Return l (or r) when l = r.

*/

class Solution {
public:
    
    bool  feaseable(vector<int>& weights, int c , int days)
    {
        int daysNeed = 1 , currentLoad =0;

        for(int weight : weights)
        {
            currentLoad += weight;

            if(currentLoad > c)
            {
                currentLoad = weight;
                daysNeed++;
            }
        }
        return daysNeed <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        
        int n = weights.size(), mx =0, total=0;
        
        for(int weight : weights)
        {
            total += weight;
            mx= max(mx, weight);
        }
        int l = mx, r = total;

        while(l < r)
        {
            int mid = (l+r)>>1;

            if(feaseable(weights, mid, days))
            r = mid;
            else 
            l = mid+1;
        }
        return l;
    }
};
