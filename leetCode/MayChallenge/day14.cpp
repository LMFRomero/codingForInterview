typedef struct _node {
    char value;
    bool end;
    struct _node *next[26];
} Node;

Node* create(char new_value) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->value = new_value;
    node->end = false;
    for (int i = 0; i < 26; i++)
        node->next[i] = NULL;
    
    return node;
}

class Trie {
private:
    Node *root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = create('?');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *tmp = root;
        for (char c : word) {
            if (tmp->next[(int) c - (int) 'a'] == NULL)
                tmp->next[(int) c - (int) 'a'] = create(c);
            
            tmp = tmp->next[(int) c - (int) 'a'];
        }
        tmp->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *tmp = root;
        for (char c : word) {
            if (tmp->next[(int) c - (int) 'a'] == NULL)
                return false;
            else
                tmp = tmp->next[(int) c - (int) 'a'];
        }
        
        return tmp->end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *tmp = root;
        for (char c : prefix) {
            if (tmp->next[(int) c - (int) 'a'] == NULL)
                return false;
            else
                tmp = tmp->next[(int) c - (int) 'a'];
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
