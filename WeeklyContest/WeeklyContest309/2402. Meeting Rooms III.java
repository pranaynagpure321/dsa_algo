/*2402. Meeting Rooms III
User Accepted:1268
User Tried:2455
Total Accepted:1360
Total Submissions:6350
Difficulty:Hard
You are given an integer n. There are n rooms numbered from 0 to n - 1.

You are given a 2D integer array meetings where meetings[i] = [starti, endi] means that a meeting will be held during the half-closed time interval [starti, endi). All the values of starti are unique.

Meetings are allocated to rooms in the following manner:

Each meeting will take place in the unused room with the lowest number.
If there are no available rooms, the meeting will be delayed until a room becomes free. The delayed meeting should have the same duration as the original meeting.
When a room becomes unused, meetings that have an earlier original start time should be given the room.
Return the number of the room that held the most meetings. If there are multiple rooms, return the room with the lowest number.

A half-closed interval [a, b) is the interval between a and b including a and not including b.*/


class Solution {
    public int mostBooked(int n, int[][] meetings) {
             int ans =0;

        Arrays.sort(meetings , (a,b) -> a[0]-b[0]);
        //Hashtable<Integer, LinkedList<Pair<Integer, Integer>> > mp = new Hashtable<>();
        HashMap<Integer,LinkedList<Pair<Long, Long>> > mp = new HashMap<>();

        for( int[] meet  : meetings)
        {
            long minend = Long.MAX_VALUE;
            int roomfornextMeet =-1;
            for( int i =0 ;i< n ;i++)
            {
                if(!mp.containsKey(i))
                {
                    LinkedList<Pair<Long,Long>> list= new LinkedList<>();
                    var p = new Pair<>((long)meet[0], (long)meet[1]);
                    list.add(p);
                    mp.put(i, list);
                    roomfornextMeet =-1;
                    break;
                }
                else
                {
                    var list = mp.get(i);
                    var p = list.getFirst();

                    //no overlappign case
                    if(meet[0] - p.getValue() >= 0)
                    {
                        minend = 0;
                        roomfornextMeet = i;
                        break;
                    }
                    //overlapping case
                    if(Math.abs(meet[0] - p.getValue()) < minend)
                    {
                        minend = Math.abs(p.getValue() - meet[0]);
                        roomfornextMeet  = i;
                    }
                }
            }

            if (roomfornextMeet!= -1 && minend != Integer.MAX_VALUE)
            {
                var p = new Pair<>(meet[0] + minend , meet[1]+minend);
                mp.get(roomfornextMeet).addFirst(p);

            }
        }
        int max = -1;
        for(int i =0 ;i< n ;i++)
        {
            if( mp.containsKey(i) && max <  mp.get(i).size())
            {
                max = mp.get(i).size();
                ans =i;
            }
        }

        return ans;
    }
}
