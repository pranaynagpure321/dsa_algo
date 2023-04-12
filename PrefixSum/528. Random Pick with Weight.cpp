class Solution {
public:
    vector<int> weight;
    int sum =0;
    Solution(vector<int>& w) {
        weight.push_back(w[0]);

        for(int i =1 ;i< w.size(); ++i)
        {
            weight.push_back(weight[i-1]+ w[i]);
        }

        sum = weight[weight.size() - 1];
    }
    
    int pickIndex() {

        int n = rand()% sum; // generate random number and mod by total prefix sum
        auto it = upper_bound(weight.begin(), weight.end(), n); //find upeer bound iterator to  the number 
        return it - weight.begin(); //subtract the begin iterator to return index
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
