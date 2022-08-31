/*703. Kth Largest Element in a Stream
Easy

3353

1949

Add to List

Share
Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Implement KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
int add(int val) Appends the integer val to the stream and returns the element representing the kth largest element in the stream.
 */

class KthLargest {
public:
     priority_queue<int, vector<int>, greater<int>> pq;
     int k = 0;
    KthLargest(int k, vector<int>& nums) { 
       this->k = k;
       pq = priority_queue<int, vector<int>, greater<int>>();
        
        for(int &i : nums)
        {
            pq.push(i);
        }
    }
    
    int add(int val) {
        
       pq.push(val);
        
       while(pq.size() > k) pq.pop();

        return pq.top();
    }
};
