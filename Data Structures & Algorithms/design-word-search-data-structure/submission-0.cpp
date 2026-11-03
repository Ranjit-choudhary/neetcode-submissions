#include <cstring>
class WordDictionary {
public:
    WordDictionary() {
    }
        struct node{
            node *link[26];
            bool isEnd;
            node(){
                memset(link,0,sizeof(link));
                isEnd = false;
            }
            
        };
    node *root = new node();
    void addWord(string word) { 
        node *temp = root;
        for(char c:word){
            int idx = c-'a';
            if(temp->link[idx] == NULL){
                temp->link[idx] =  new node();
            }
            temp = temp->link[idx];
        }
        temp->isEnd = 1;
    }
    
    bool dfs(string &word, int pos, node *temp){

        if(pos == word.size()) return temp->isEnd;

        if(word[pos] == '.'){
            for(int i =0;i<26;i++){
                if(temp->link[i] != NULL){

                if(dfs(word,pos+1,temp->link[i])) return true;
                }
            }
            return false;
        }
        else{

            char c = word[pos];
            int idx = c-'a';
            if(temp->link[idx] == NULL){
                return false;
            }
            temp = temp->link[idx];
        return dfs(word,pos+1,temp);
        }
        
        
    }
    bool search(string word) {
        return dfs(word,0,root);
    }
};
