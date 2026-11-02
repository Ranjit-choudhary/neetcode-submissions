#include <cstring>
class PrefixTree {
public:
    struct node{
        node *link[26];
        bool isEnd;
        node(){
        isEnd = false;
        memset(link,0,sizeof(link));    
        }
    };
        node *root = new node();
    PrefixTree() {
    }
    
    void insert(string word) {
        node *ptr = root;
        for(char c:word){
            int idx = c- 'a';
            if(ptr->link[idx] == NULL){
                ptr->link[idx] = new node();
            }
            ptr = ptr->link[idx];
        }
        ptr->isEnd  = true;
    }
    
    bool search(string word) {
        node *ptr = root;
        for(char c:word){
            int idx = c- 'a';
            if(ptr->link[idx] == NULL){
                return false;
            }
            ptr = ptr->link[idx];
        }
        if(ptr->isEnd == false) return false;
        return true;
    }
    
    bool startsWith(string prefix) {
        node *ptr = root;
        for(char c:prefix){
            int idx = c- 'a';
            if(ptr->link[idx] == NULL){
                return false;
            }
            ptr = ptr->link[idx];
        }
        return true;
    }
};
