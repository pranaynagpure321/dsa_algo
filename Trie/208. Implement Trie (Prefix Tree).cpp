class TrieNode
{
 public:
    char c;
    vector<TrieNode*> vec ;             // use pointer to class varible imp
    int finish;                         //using vector to store trie tree structure  
    //int cnt;
    
    TrieNode(char c  )                      
    {
        this->c= c;
        this->vec = vector<TrieNode*>(26,NULL);
        finish =0;
        //cnt =0;
    }
};


class Trie {
public:
    
    TrieNode *root = NULL;
    Trie() {
        root = new TrieNode('$');
    }
    
    void insert(string word) {
        
        TrieNode *tmp = root;                            // traverse through word and also tree if node is null insert new node at that point
        for(int i =0 ;i< word.length(); ++i)
        {
            int idx  = word[i] - 'a';
            if(tmp->vec[idx] == NULL)
                tmp->vec[idx]= new TrieNode(word[i]);
            tmp = tmp->vec[idx];
        }
        tmp->finish++;
    }
    
    bool search(string word) {
        
        TrieNode *tmp = root;                          //use similar to insert to search the word i trie
        for(int i =0 ;i< word.length(); ++i)
        {
            int idx = word[i] - 'a';   
            if(tmp->vec[idx] == NULL)
                return false;
            tmp = tmp->vec[idx];
        }
        
        if(tmp->finish)                                 //if finish is not zero means there is word
        return true;
        
        return false;
    }
    
    bool startsWith(string prefix) {
        
        TrieNode *tmp = root;                                       // use similar to search to find prefix just dont chheck finish var
        for(int i =0 ;i< prefix.length(); ++i)
        {
            int idx = prefix[i] - 'a';
            
            if(tmp->vec[idx] == NULL)
                return false;
            
            tmp = tmp->vec[idx];
        }
        return true;
      
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
