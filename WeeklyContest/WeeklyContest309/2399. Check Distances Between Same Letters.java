/*2399. Check Distances Between Same Letters
User Accepted:10917
User Tried:11678
Total Accepted:11214
Total Submissions:16391
Difficulty:Easy
You are given a 0-indexed string s consisting of only lowercase English letters, where each letter in s appears exactly twice. You are also given a 0-indexed integer array distance of length 26.

Each letter in the alphabet is numbered from 0 to 25 (i.e. 'a' -> 0, 'b' -> 1, 'c' -> 2, ... , 'z' -> 25).

In a well-spaced string, the number of letters between the two occurrences of the ith letter is distance[i]. If the ith letter does not appear in s, then distance[i] can be ignored.

Return true if s is a well-spaced string, otherwise return false.

 

Example 1:

Input: s = "abaccb", distance = [1,3,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
Output: true
Explanation:
- 'a' appears at indices 0 and 2 so it satisfies distance[0] = 1.
- 'b' appears at indices 1 and 5 so it satisfies distance[1] = 3.
- 'c' appears at indices 3 and 4 so it satisfies distance[2] = 0.
Note that distance[3] = 5, but since 'd' does not appear in s, it can be ignored.
Return true because s is a well-spaced string.*/


class Solution {
    public boolean checkDistances(String s, int[] distance) {
         HashMap<Character, Integer> mp = new HashMap<>();

        for(int i =0 ;i<s.length(); i++)
        {
            char c = s.charAt(i);

            if(!mp.containsKey(c))
            {
                mp.put(c,i);
            }
            else
            {
                int val = mp.get(c);
                val = i - (val +1);

                if(val != distance[c-'a'])
                    return false;
            }
        }

        return true;
    }
}
