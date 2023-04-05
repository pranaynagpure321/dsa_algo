/*
881. Boats to Save People
Medium
5.3K
120
company
Google
company
Amazon
company
Salesforce
You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats where each boat can carry a maximum weight of limit. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.

Return the minimum number of boats to carry every given person.

 

Example 1:

Input: people = [1,2], limit = 3
Output: 1
Explanation: 1 boat (1, 2)
*/


class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int i =0 ,j = people.size()-1,cnt=0;
        while(i<=j)
        {
            if(people[j] == limit)
            {
                cnt++; j--;
            }
            else if(people[i] +people[j] <= limit)
            {
                cnt++; i++;j--;
            }
            else if(people[i]+ people[j] > limit)
            {
                cnt++; j--;
            }
        }
        return cnt;
    }
};
