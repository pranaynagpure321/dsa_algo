class SeatManager {
public:
    //declare pq so that we can maintain min seat at top and remove that once reserve is called then when unreserve is called we can push the seatNumber if that num is less tha reserve the it will be at top
    priority_queue<int,vector<int>,greater<int>> pq;
    SeatManager(int n) {
        pq = priority_queue<int, vector<int>,greater<int>>();
        for(int i =1 ;i<=n ;i++)
        pq.push(i);
    }
    
    int reserve() {
        int t = pq.top();
        pq.pop();
        return t;
    }
    
    void unreserve(int seatNumber) {
       pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
