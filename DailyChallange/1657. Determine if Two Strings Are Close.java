class Solution {

    boolean isEqual(int[] char_counts1 , int[] char_counts2)
    {
        for(int i =0 ;i<26 ;i++)
        {
            if(char_counts1[i] != char_counts2[i]) return false;
        }
        return true;
    }

    public boolean closeStrings(String word1, String word2) {
        if(word1.length() != word2.length())
        return false;

        int[] char_counts1 = new int[26];
        for(char c : word1.toCharArray())
         char_counts1[c-'a']++;
        
        int[] char_counts2 = new int[26];
        for(char c : word2.toCharArray())
            char_counts2[c-'a']++;
        for(int i =0 ;i< 26 ;i++)
        {
            if(char_counts1[i] > 0 && char_counts2[i] == 0) return false;
        }

        Arrays.sort(char_counts1);
        Arrays.sort(char_counts2);

        return isEqual(char_counts1, char_counts2);
    }
}
