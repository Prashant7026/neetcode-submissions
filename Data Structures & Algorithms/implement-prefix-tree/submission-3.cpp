struct TrieNode {
    bool eow = false;
    map<char, TrieNode*> mp;

    bool containsKey(char ch) {
        return mp.find(ch) != mp.end();
    }

    void put(char ch, TrieNode* node) {
        mp[ch] = node;
    }

    TrieNode* get(char ch) {
        auto it = mp.find(ch);
        return (it != mp.end()) ? it->second : nullptr;
    }
};

class PrefixTree {
private:
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    /*
    if(found the character)     go there;
    else    create -> add -> go there;
    */
    void insert(string word) {
        TrieNode* temp = root;

        for(auto i: word) {
            if (!temp->containsKey(i)) {
                temp->put(i, new TrieNode());
            }
            
            temp = temp->get(i);
        }

        temp->eow = true;
    }
    
    bool search(string word) {
        TrieNode* temp = root;

        for(char ch: word) {
            if(!temp->containsKey(ch)) {
                return false;
            }
            temp = temp->get(ch);
        }

        return temp->eow;
    }
    
    bool startsWith(string prefix) {
        TrieNode* temp = root;

        for(char ch: prefix) {
            if(!temp -> containsKey(ch)) {
                return false;
            }

            temp = temp -> get(ch);
        }

        return true;
    }
};
