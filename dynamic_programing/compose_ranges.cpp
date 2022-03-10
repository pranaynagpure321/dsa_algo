/*Given a sorted integer array that does not contain any duplicates, return a summary of the number ranges it contains.

Example

For nums = [-1, 0, 1, 2, 6, 7, 9], the output should be
solution(nums) = ["-1->2", "6->7", "9"]. */

#include <iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> solution(vector<int> nums) {
   
    vector<string> ans;
    if(nums.size()<1)
    return ans;
    if(nums.size()==1)
    {
        ans.push_back(to_string(nums[0]));
        return ans;
    }
    for(int i =0 ; i< nums.size();i++)
    {
        for(int j =i ;j<nums.size();j++)
        { 
            int end = j+1;
            if(end==nums.size() && i==j)
            {
                ans.push_back(to_string(nums[i]));
                return ans;
            }
            if( nums[j]+1!=nums[end])
            {
                string temp;
               if(i==j){
                temp =to_string(nums[i]); 
               }
               else{
                temp = to_string(nums[i])+"->"+to_string(nums[j]);
               }
               ans.push_back(temp);  
               i=j+1;
            }
            
        }
    }
    return ans;
}
int main()
{
    //printf("Hello World");
   vector<int> nums {-1, 0, 1, 2, 6, 7, 9};
    
    std::cout << solution(nums) << std::endl;

    return 0;
}
