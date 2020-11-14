class TrieNode {
public:
    int value;
    TrieNode* children[26] = {NULL};
    TrieNode* fail;
    bool isEnd;
    TrieNode() : value(-1), fail(NULL), isEnd(false) {}
    TrieNode(char charValue) : value(charValue-'a'), fail(NULL), isEnd(false) {}
};

class StreamChecker {
public:
    StreamChecker(vector<string>& words) {
        buildTrie(words);
        buildFail();
        current = &root;
    }
    
    bool query(char letter) {
        while(current != &root) {
            if(current->children[letter-'a'] != NULL) {
                current = current->children[letter-'a'];
                if(current->isEnd == false) {
                    TrieNode* temp = current;
                    while(temp != &root) {
                        if(temp->isEnd == true) {
                            return true;
                        } else {
                            temp = temp->fail;
                        }
                    }
                    return false;
                } else {
                    return true;
                }
            } else {
                current = current->fail;
            }
        }
        if(root.children[letter-'a'] != NULL) {
            current = root.children[letter-'a'];
            return current->isEnd;
        }
        return false;
    }

    ~StreamChecker() {
        for(int i=0; i<26; i++) {
            if(root.children[i] != NULL) {
                releaseChildren(root.children[i]);
            }
        }
    }

    void releaseChildren(TrieNode* temp) {
        for(int i=0; i<26; i++) {
            if(temp->children[i] != NULL) {
                releaseChildren(temp->children[i]);
            }
        }
        delete temp;
    }

    void buildTrie(vector<string> &words) {
        TrieNode* temp_current;
        for(string word: words) {
            temp_current = &root;
            for(char c: word) {
                if(temp_current->children[c-'a'] == NULL) {
                    temp_current->children[c-'a'] = new TrieNode(c);
                }
                temp_current = temp_current->children[c-'a'];
            }
            temp_current->isEnd = true;
        }
    }

    void buildFail() {
        root.fail = &root;
        queue<TrieNode*> process_queue;
        for(int i=0; i<26; i++) {
            if(root.children[i] != NULL) {
                root.children[i]->fail = &root;
                process_queue.push(root.children[i]);
            }
        }
        while(!process_queue.empty()) {
            TrieNode* temp_current = process_queue.front();
            process_queue.pop();
            for(int i=0; i<26; i++) {
                if(temp_current->children[i] != NULL) {
                    setFailForChild(temp_current, i);
                    process_queue.push(temp_current->children[i]);
                }
            }
        }
    }

    void setFailForChild(TrieNode* parent, int child_index) {
        TrieNode* to_search = parent->fail;
        while(to_search != &root) {
            if(to_search->children[child_index] != NULL) {
                parent->children[child_index]->fail = to_search->children[child_index];
                return;
            }
            to_search = to_search->fail;
        }
        if(root.children[child_index] != NULL) {
            parent->children[child_index]->fail = root.children[child_index];
            return;
        }
        parent->children[child_index]->fail = &root;
    }

    TrieNode root;
    TrieNode* current;
};

// https://www.cnblogs.com/RDaneelOlivaw/p/10922396.html