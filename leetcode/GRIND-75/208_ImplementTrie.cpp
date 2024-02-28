class Trie {
        Trie* children[26];
        bool endofword;
public:
    /** Initialize your data structure here. */
    Trie() {
        endofword = false;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int n = word.length();
        Trie* temp = this;
        for(int i=0; i<n; i++){
            int idx = word[i] - 'a';
            if(temp->children[idx] == NULL){
                temp->children[idx] = new Trie;
            }
            temp = temp -> children[idx];
        }
        temp->endofword = true;
    }
    
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int n = word.length();
        Trie* temp = this;
        for(int i=0; i<n; i++){
            int idx = word[i] - 'a';
            if(temp->children[idx] == NULL){
                return false;
            }
            temp = temp -> children[idx];
        }
        return temp->endofword;
           
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int m = prefix.length();
        Trie* temp = this;
        for(int i=0; i<m; i++){
            int idx = prefix[i] - 'a';
            if(temp->children[idx] == NULL)
                return false;
            temp = temp-> children[idx];
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