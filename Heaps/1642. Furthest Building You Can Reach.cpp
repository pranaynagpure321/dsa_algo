 
 /*   
1642. Furthest Building You Can Reach
Medium

Share
You are given an integer array heights representing the heights of buildings, some bricks, and some ladders.

You start your journey from building 0 and move to the next building by possibly using bricks or ladders.

While moving from building i to building i+1 (0-indexed),

If the current building's height is greater than or equal to the next building's height, you do not need a ladder or bricks.
If the current building's height is less than the next building's height, you can either use one ladder or (h[i+1] - h[i]) bricks.
Return the furthest building index (0-indexed) you can reach if you use the given ladders and bricks optimally.

Example 1:

Input: heights = [4,2,7,6,9,14,12], bricks = 5, ladders = 1
Output: 4
Explanation: Starting at building 0, you can follow these steps:
- Go to building 1 without using ladders nor bricks since 4 >= 2.
- Go to building 2 using 5 bricks. You must use either bricks or ladders because 2 < 7.
- Go to building 3 without using ladders nor bricks since 7 >= 6.
- Go to building 4 using your only ladder. You must use either bricks or ladders because 6 < 9.
It is impossible to go beyond building 4 because you do not have any more bricks or ladders.
Example 2:

Input: heights = [4,12,2,7,3,18,20,3,19], bricks = 10, ladders = 2
Output: 7*/
    
 Class Solution{
  public :
  
  
  int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        
        priority_queue<int,vector<int> , greater<int> > pq;   // min heap to store laast used minimum ladder
        
        for(int i =1 ;i< heights.size() ; i++)
        {
           int diff = heights[i] - heights[i-1];
               if( diff <= 0) continue;
            
                if(pq.size() < ladders)                 // use all the ladders first
                    pq.push(diff);
            
                else
                {
                    int br = diff;
                    if(pq.size() >0 and pq.top() < diff)             // then check if top of min heap contain small value that current 
                    {
                        br = pq.top();                               //jump if yes then replace jump
                        pq.pop();                                     // 2, 7, 9, 3, 1, 2, 5, 9, 4, 6 b= 8 , l = 2 , this case explain
                        pq.push(diff);                                 // the scenario, only take longest jumps with ladder 
                    }
                    
                    bricks -= br;
                    
                    if(bricks<0)
                        return i-1;
                }
        }
        
        //time nlogn
        //space O(n)
        return heights.size() -1;
    }
};
