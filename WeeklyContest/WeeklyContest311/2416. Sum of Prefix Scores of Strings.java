class TrieNode {

    char c ;
    TrieNode[] vec ;                 // node array to store all the node from curr node
    int finish;                  // if word finish with that character
    int cnt ;                      // cnt to store words ended after that character

    public TrieNode(Character c)
    {
        this.c =c;
        this.vec = new TrieNode[26];
        finish =0;
        cnt=0;
    }
}
class Trie
{
    TrieNode root;

    Trie()
    {
        root = new TrieNode('$');                // emptry node at start
    }

    public void insert(String s)
    {
        TrieNode tmp = root;

        for (int i =0 ;i<s.length() ; i++ )
        {
            int idx = s.charAt(i) -'a';
            if(tmp.vec[idx] == null )
                tmp.vec[idx] = new TrieNode(s.charAt(i));               // insert word based on character location
            tmp = tmp.vec[idx];
        }
        tmp.finish++;
    }


    int dfs(TrieNode root)                             // dfs on trie to find out total no of words in that part of tree
    {
        if (root == null) return 0; 

        int temp =0;
        for(int i =0 ;i< 26 ; i++)
        {
            temp+= dfs(root.vec[i]);
        }

        if (root.finish >0 ) temp+=root.finish;

        return root.cnt =temp;
    }

    int getAns(String s)
    {
        int ans =0;
        TrieNode tmp = root;
        for(int i =0 ;i< s.length(); i++)             // interate through evry charcter to find total words starting with that char
        {
            char c = s.charAt(i);
            tmp = tmp.vec[c-'a'];
            ans+= tmp.cnt;
        }

        return ans; //return ans
    }
}

class Solution {
    
    public int[] sumPrefixScores(String[] words) {
        
        // create Trie DS
        Trie t = new Trie();

        for (var s : words)
        {
            t.insert(s);           //insert every word
        }

        t.dfs(t.root);           //dfs on every node to find number of words from that node

        int[] ans = new int[words.length];           

        for (int i =0 ;i< words.length ; i++)
        {
            ans[i] = t.getAns(words[i]);          //get prefix ans for every word
        }
       //https://www.youtube.com/watch?v=ZZEaS3CAZ4U&ab_channel=BroCoders video solution
        //time n*n => n2 words length * array length
        return ans;
    }
}
