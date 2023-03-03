struct Trie{
    unordered_map<char, Trie *> child;
    bool end;
    Trie() {
        end = false;
    }
    void insert(string s) {
        Trie* curr = this;
        for (char c : s) {
            if (!curr->child.count(c))
                curr->child[c] = new Trie ();
            curr = curr->child[c];
        }
        curr->end = true;
    }
    bool search(string s) {
        Trie * curr =  this ;
        for (char  c : s) {
            if (!curr->child.count(c))
                return false;
            curr = curr->child[c];
        }
        return curr->end;
    }
};
