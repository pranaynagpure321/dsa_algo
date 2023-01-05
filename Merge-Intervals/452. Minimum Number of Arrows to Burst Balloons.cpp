class Solution {
public:

/*Greedy algorithms

Greedy problems usually look like "Find minimum number of something to do something" or "Find maximum number of something to fit in some conditions", and typically propose an unsorted input.*/

/*
basically merge the intervals taking smaller inerval into account
*/
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int res =0,   endpoint = points[0][1];
        for(int i = 1; i< points.size();i++)
        {
            if(endpoint< points[i][0]) //check the endpoints with each interval 
            {
                res++;
                endpoint = points[i][1];
            }
            else if(endpoint > points[i][1])
            {
                //res++;
                endpoint = points[i][1];
            }
        }

        //

        return res+1;
    }
};
