/*2405. Optimal Partition of String
Medium
Share
Given a string s, partition the string into one or more substrings such that the characters in each substring are unique. That is, no letter appears in a single substring more than once.

Return the minimum number of substrings in such a partition.

Note that each character should belong to exactly one substring in a partition.


Example 1:

Input: s = "abacaba"
Output: 4
Explanation:
Two possible partitions are ("a","ba","cab","a") and ("ab","a","ca","ba").
It can be shown that 4 is the minimum number of substrings needed.*/


class Solution {
    public int partitionString(String s) {
         int count =0;

        int i = 0;

        //LinkedList<String> list = new LinkedList<>();
        int[] char_counts= new int[26];
        int j =0;
        for(;j< s.length() ;j++)
        {
            char c = s.charAt(j);

            char_counts[c-'a']++;

            if(char_counts[c-'a']>1)
            {
                for(int m = i ; m<j && m<s.length() ;m++)
                    char_counts[s.charAt(m) - 'a']--;
                //list.add(s.substring(i,j));
                count++;
                i=j;
            }
        }

        if(j-i >0)
        {
            //list.add(s.substring(i,j));
            count++;
        }

        return count;
    }
}
