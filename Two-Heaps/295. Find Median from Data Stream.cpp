class MedianFinder {
public:
    
    //maintain two heap one for lower half other for upperhalf
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    int count ;
    MedianFinder() {
        //initialiaze the both heaps
        maxheap = priority_queue<int>();
        minheap = priority_queue<int, vector<int>, greater<int>>();
        count =0;
    }
    
    void addNum(int num) {
        
       
        if(maxheap.size() == 0) maxheap.push(num);  //if maxheap is empty then directlypush onto it
        
        else if(maxheap.size() > minheap.size()) 
        {
            //if size of maxheap is greater then  find mini element from current number and top of maxheap
            
            int choosemin = min( maxheap.top(), num);
            int choosemax = max( maxheap.top(),num);
            maxheap.pop();
            maxheap.push(choosemin);         //push minimum element on to maxheap
            minheap.push(choosemax);         //push maximum element on to minheap
        }
        else
        {
             //if size of minheap is greater or equal to maxheap,  find mini element from current number and top of minheap
            
            int choosemin = min(minheap.top(), num);
            int choosemax = max(minheap.top(),num);
            minheap.pop();
            maxheap.push(choosemin);   //push minimum of those two element on maxheap
            minheap.push(choosemax);   //push max of those two on min heap
        }
        
        count++;
    }
    
    double findMedian() {
        if(count%2 !=0 )  //find median if no of elemnts is not even
        {
            if(maxheap.size() > minheap.size() )
                return maxheap.top();
            else
                minheap.top();
        }
        
        return  (maxheap.top() + minheap.top())/2.0;    //return median if size is even
    }
    
    
    //time (nlogn)
    //space o(n)
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
