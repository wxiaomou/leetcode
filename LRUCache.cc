class LRUCache{
public:
    struct ListNode {
       int val;
       int key;
       ListNode *next;
       ListNode(int x, int y) : val(x), key(y), next(NULL) {}
    };
    
    int capacity;
    ListNode *head;
    ListNode *tail;
    map<int, ListNode *> hash;
    int length;
    LRUCache(int capacity) {
        this->capacity = capacity;
        length = 0;
        head = NULL;
        tail = NULL;
    }
    
    int get(int key) {
        if (hash.find(key) == hash.end()) return -1;
        int ret = hash.find(key)->second->val;
        ListNode *cur = hash.find(key)->second;
        
        if (!cur->next) 
            return ret;
        ListNode *new_tail = new ListNode(cur->val, cur->key);
        cur->val = cur->next->val;
        cur->key = cur->next->key;
        ListNode *tmp = cur->next;
        cur->next = cur->next->next;
        delete(tmp);
        hash.find(cur->key)->second = cur;
        hash.find(key)->second = new_tail;
        if (!cur->next)
            tail = cur;

        tail->next = new_tail;
        tail = tail->next;
        return ret;
    }
    
    void set(int key, int value) {
        if (hash.find(key) != hash.end()) {
            get(key);
            hash.find(key)->second->val = value;
            return;
        }
        ListNode *cur = new ListNode(value, key);
        if (length < capacity) {
            if (!head) {
                head = cur;
                tail = head;
            } else {
                tail->next = cur;
                tail = tail->next;
            }
            length++;
            hash.insert(pair<int, ListNode *>(key, cur));
        } else {
            ListNode *tmp = head;
            head = head->next;
            if (tmp)
                delete(tmp);
            hash.erase(tmp->key);
            hash.insert(pair<int, ListNode *>(key, cur));
            tail->next = cur;
            tail = tail->next;
            hash[key] = cur;
        }
    }
};

// Simplify one
struct Node {
     int val;
     int key;
     Node(int x, int y) : val(x), key(y) {}
};
class LRUCache{
private:
int size;
list<Node> q;
map<int, list<Node>::iterator> hash;
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if (hash.find(key) == hash.end()) return -1;
        q.splice(q.begin(), q, hash[key]);
        hash[key] = q.begin();
        return (*hash[key]).val;
    }
    
    void set(int key, int value) {
        if (hash.find(key) != hash.end()) {
            get(key);
            (*hash[key]).val = value;
            return;
        }
        Node tmp(value, key);
        if (q.size() < size) {
            q.push_front(tmp);
            hash[key] = q.begin();
        } else {
            int _key = (q.back()).key;
            q.pop_back();
            hash.erase(_key);
            q.push_front(tmp);
            hash[key] = q.begin();
        }
    }

};