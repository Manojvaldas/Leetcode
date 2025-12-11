class Node {
public:
    int key, val;
    Node* prev;
    Node* next;

    Node() {
        key = -1;
        val = -1;
        prev = NULL;
        next = NULL;
    }

    Node(int k, int v) {
    key = k;
    val = v;
    prev = next = NULL;
    }
};



class LRUCache {
private:
    map<int, Node* > mpp;
    int cap;
    Node* head;
    Node* tail;

    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insertAfterHead(Node* node) {
        Node* nextNode = head->next;
        head->next = node;
        nextNode->prev = node;
        node->prev = head;
        node->next = nextNode;
    }
public:
    LRUCache(int capacity) {
        cap = capacity;
        mpp.clear();

        head = new Node();
        tail = new Node();

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {

        if(mpp.find(key) == mpp.end()) return -1;
        Node* node = mpp[key];
        int val = node->val;
        deleteNode(node);
        insertAfterHead(node);
        return val;
        
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()) {
            Node* node = mpp[key];
            node->val = value;

            deleteNode(node);
            insertAfterHead(node);
            return;
        }

        //check for map capacity
        if(mpp.size() == cap) {
            Node* node = tail->prev;
            mpp.erase(node->key);
            deleteNode(node);
            delete node;
        }

        Node* newNode = new Node(key, value);
        mpp[key] = newNode;
        insertAfterHead(newNode);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */