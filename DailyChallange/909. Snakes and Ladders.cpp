/*Find the cell (row,column)(\text{row}, \text{column})(row,column) associated with each label from 111 to n2n^2n 
2
 . Start from the bottom left cell and traverse the board alternately left to right and right to left. One can do this by maintaining the order of columns and reversing it after each row.

Maintain a queue of cells and an array to store distances to all cells from the first one. By distance to the cell, we mean the least number of moves required to reach it. The distance from the first cell to itself is 000. Mark all other cells as initially unreachable from the first one (we denote the distance to such cells with −1-1−1). Push the first cell to the queue.

While the queue is not empty:

Pop a cell from the queue. Let's say its label is curr\text{curr}curr. For each square next\text{next}next with a label in the range curr+1\text{curr} + 1curr+1 to min⁡(curr+6,n2)\min(\text{curr} + 6, n^2)min(curr+6,n 
2
 ) (as described by the problem), if next\text{next}next has a snake or a ladder, set destination\text{destination}destination to the destination of that snake or ladder. Otherwise, set destination\text{destination}destination to next\text{next}next.

If dist[destination]\text{dist[destination]}dist[destination] is −1-1−1 (i.e. the destination\text{destination}destination has not been visited yet) set dist[destination]\text{dist[destination]}dist[destination] to dist[curr]+1\text{dist[curr]} + 1dist[curr]+1 (the number of moves to get to the current cell, plus one more move to get to destination\text{destination}destination) and push destination\text{destination}destination on to the queue.

Return the distance to cell n2n^2n 
2
 . If it is unreachable, the result will be −1-1−1.*/

class Solution {
public:
    
    vector<int> flattenboards(vector<vector<int>>& board, int n){
        vector<int> flat(n*n,-1);
        int k=0;
        bool righttoleft = true;
        for(int i =n-1 ; i>=0  ; --i)
        {
            if(righttoleft)
            {
                for(int j = 0 ;j< n ; ++j)
                flat[k++] = board[i][j];
            }
            else
            {
                for(int j = n-1 ; j>=0 ;--j)
                flat[k++] = board[i][j];
            }
            righttoleft = !righttoleft;
        }
        return flat;
    }

    int snakesAndLadders(vector<vector<int>>& board) {
       int n = board.size();
       auto flat = flattenboards(board,n);
      

        int level =0;
        queue<int> q; q.push(0);
        vector<int> dist(n*n,-1);
        dist[0] = 0;
        while(q.size() >0)
        {
            int  curr = q.front(); q.pop();
            if(curr == n*n -1) return dist[curr];

            for(int k = 1 ; k<= 6 ; k++)
            {   
                int next = curr + k;
                if(next >= n*n) continue;

                if(flat[next] != -1 )
                {
                    next = flat[next] -1;
                }
                if(dist[next] ==  -1)  {
                    q.push(next);
                    dist[next] = dist[curr] +1;
                }
            }
        }
        return -1;
    }
};
