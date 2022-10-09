class MyLinkedList {
    
    struct Node {
        int data;
        Node *next;
        Node *prev;
        
        Node(int data) {
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
    };
    
    Node *head, *tail;
    int size = 0;
    
    
    Node* traverseFromHead(Node *head, int k) {
        Node *tmp = head;
        
        while(tmp && k>0) {
            tmp = tmp->next;
            --k;
        }
        return tmp;
    }
    
public:
    MyLinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    
    int get(int index) {
        if (index >= size) {
            return -1;
        }
        
        Node *result = NULL;
        result = traverseFromHead(head, index);
        return result->data;
    }
    
    void addAtHead(int val) {
        Node *newNode = new Node(val);
        
        if (!head && !tail) {
            head = newNode;
            tail = head;
        } else {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
        ++size;
    }
    
    void addAtTail(int val) {
        Node *newNode = new Node(val);
        
        if (!head && !tail) {
            head = newNode;
            tail = head;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        ++size;
    }
    
    void addAtIndex(int index, int val) {
        
        if(index > size)
            return;
        
        if (index == 0) {
            addAtHead(val);
            return;
        }
        
        if (index == size) {
            addAtTail(val);
            return;
        }
        Node *result = NULL;
        Node *newNode = new Node(val);
        
        result = traverseFromHead(head, index);
        
        newNode->prev =result->prev;
        newNode->next = result;
        
        if (result->prev) {
            result->prev->next = newNode;
        }
        
        result->prev = newNode;
        ++size;
    }
    
    void deleteAtIndex(int index) {
        
        if (index >= size)
            return;
        
        Node *result = NULL;
        result = traverseFromHead(head, index);
        
        if (result->prev)
            result->prev->next = result->next;
        
        if (result->next)
            result->next->prev = result->prev;
        
        if (index == 0)
            head = head->next;
        
        if (index == size -1) {
            tail = tail->prev;
        }
        result->prev = NULL;
        result->next = NULL;
        delete(result);
        --size;
    }
};