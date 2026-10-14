class LRUCache {
public:
    struct ll{
        int key;
        int value;
        struct ll *left ;
        struct ll *right;
    };
    int c;
    int count =0;
    struct ll *head;
    struct ll *tail;
        unordered_map<int,struct ll*> mp;
    LRUCache(int capacity) {
        c = capacity;
        head = new struct ll{};
        tail = new struct ll{};
        head ->right = tail;
        tail->left = head;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        else{
           struct ll* temp = mp[key]; 
            temp->left->right = temp->right;
            temp->right->left = temp->left;
            temp->left = head;
            temp->right = head->right;
            head->right->left = temp;
            head->right = temp;
            
        return temp->value;
        }
    }
    
    void put(int key, int value) {
        if(c==0) return ;
        if(mp.find(key) == mp.end()) {
            if(count <c){
                struct ll *temp = new struct ll{};
                mp[key] = temp;
            temp->key = key;
            temp->value = value;
            temp->left = head;
            temp->right = head->right;
            head->right->left = temp;
            head->right = temp;
                count++;
                return;
            }
            struct ll *temp = tail->left;
            mp.erase(temp->key);
            temp->left->right = temp->right;
            temp->right->left = temp->left;
            mp[key] = temp;
            temp->key = key;
            temp->value = value;
           temp->left = head;
            temp->right = head->right;
            head->right->left = temp;
            head->right = temp;
        }
        else{
            struct ll *temp = mp[key];
            temp->value = value;
            temp->left->right = temp->right;
            temp->right->left = temp->left;
            temp->left = head;
            temp->right = head->right;
            head->right->left = temp;
            head->right = temp;
        }
    }
};
