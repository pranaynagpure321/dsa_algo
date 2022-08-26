/*205. Isomorphic Strings
Easy

Share
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true */



class Solution {
    public boolean isIsomorphic(String s, String t) {
        
     var map = new HashMap<Character, Character>();
        
      for( int i =0 ; i<s.length() ; i++)
      {
          char c = s.charAt(i);
          if(!map.containsKey(c) && !map.containsValue(t.charAt(i)) )
          {
              map.put(c,t.charAt(i));
          }
          else
          {
              if(map.containsKey(c)) {
                  char val = map.get(c);

                  if(val != t.charAt(i))
                  return false;
              }
              
              else
                  return false;
          }
      }
        
        //time o(n)
        //space O(n)
        return true;
        
    }
}
