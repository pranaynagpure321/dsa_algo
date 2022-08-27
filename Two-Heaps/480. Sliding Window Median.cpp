class Solution {
public:
    
    multiset<int, greater<int> > low;   //to store lower half of heap
    multiset<int>   hi;                 //to store higher haf of heap
    int count =0;                       
    void add(int num)                   // this added number in heaps
    {
        count++;
        if(low.size()== 0) low.insert(num);
        
        else if( low.size() > hi.size())
        {
            auto  top = low.begin();
            int choosmin = min(num, *top);
            int choosmax = max(num,  *top);
            low.erase(top);

            low.insert(choosmin);
            hi.insert(choosmax);
        }  
        else
        {
            auto  top = hi.begin();
            int choosmin = min(num, *top);
            int choosmax = max(num, *top);
            hi.erase(top);
            
            low.insert(choosmin);
            hi.insert(choosmax);
        }
    }
    
    void remove(int num)           // this removes number from heap
    {
        count--;
        if(num <= *low.begin())
        {
            auto it = low.find(num);
            
            if(it != low.end())
            low.erase(it);
            
        }
        else
        {
            auto it = hi.find(num);
            
            if(it != hi.end())
            hi.erase(it);
        }
    }
    
    double getMedian() //to get median value based on count
    {
        if(count%2 != 0)
        {
            
            if(low.size() > hi.size()) return *low.begin();
            
            return *hi.begin();
        }
        
        return (*hi.begin())/2.0 + (*low.begin())/2.0 ; 
    }
    
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;   
        
        low = multiset<int, greater<int> > ();
        hi  = multiset<int> ();
        count =0;
        
        int j =0;
        
        for( int i=0 ;i < nums.size() ; i++)
        {
            add(nums[i]);
            
            if(count ==  k){
                ans.push_back(getMedian());
                remove(nums[j++]);
            }
        }   
        //time n Log(n)  Lon(n) for search and deletion operation
        //space O(n);
        return ans;
    }
};
