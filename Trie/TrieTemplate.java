package com.example.practice_dsalgo;

import java.util.*;


class TrieNode {

    char c ;                         // trie node for each character
    TrieNode[] vec ;
    int finish;
    int cnt;

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
        root = new TrieNode('$');
    }

    public void insert(String s)  //insertion of strings in trie
    {
        TrieNode tmp = root;

        for (int i =0 ;i<s.length() ; i++ )
        {
            int idx = s.charAt(i) -'a';
            if(tmp.vec[idx] == null )
                tmp.vec[idx] = new TrieNode(s.charAt(i));
            tmp = tmp.vec[idx];
        }
        tmp.finish++;
    }

    void cnt()
    {
        dfs(root);
    }

    int dfs(TrieNode root)                        //dfs iteration on trie
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

   
}
public class Contest311 {

    public static int[] sumPrefixScores(String[] words) {

        Trie t = new Trie();

        for (var s : words)
        {
            t.insert(s);
        }

        t.dfs(t.root);


        return ans;
    }
}
