/*iven two sparse vectors, compute their dot product.

Implement class SparseVector:

SparseVector(nums) Initializes the object with the vector nums
dotProduct(vec) Compute the dot product between the instance of SparseVector and vec
A sparse vector is a vector that has mostly zero values, you should store the sparse vector efficiently and compute the dot product between two SparseVector.

Follow up: What if only one of the vectors is sparse?

 

Example 1:

Input: nums1 = [1,0,0,2,3], nums2 = [0,3,0,4,0]
Output: 8
Explanation: v1 = SparseVector(nums1) , v2 = SparseVector(nums2)
v1.dotProduct(v2) = 1*0 + 0*3 + 0*0 + 2*4 + 3*0 = 8*/


class SparseVector {
    
public:
   
    map<int,int> mp;
    SparseVector(vector<int> &nums) {
        
        for(int i=0 ;i< nums.size() ; i++)
        {
            if(nums[i] != 0)
                mp[i] = nums[i];
        }
        
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        
        auto mp2 = vec.mp;
        
        int ans =0;
        
        for(auto it : mp)
        {
            int key = it.first;
            
            if(mp2.find(key)!= mp2.end())
            {
                ans += mp2[key] * it.second;
            }
        }
        return ans;
        
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
