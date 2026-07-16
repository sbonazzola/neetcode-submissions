
class Node{
    public:

    int val;
    
    Node* next{};
    Node (int val) : val(val) , next(nullptr) {}

};


class LinkedList {


private:
    Node* head;
    Node* tail;
public:
    LinkedList() : head(nullptr), tail(nullptr){}


    int get(int index) {
    
        Node* cur = head;

        for (int i =0; i< index && cur!= nullptr; i++){
            cur = cur-> next;
        }

        if (cur == nullptr) return -1;
        return cur-> val;

    }

    void insertHead(int val) {
      Node* newNode = new Node(val);
      if(head == nullptr){
        head = tail = newNode;
        return;
      }

      newNode -> next = head;
      head = newNode;

    }
    
    void insertTail(int val) {

        Node* newNode = new Node(val);
        if(tail == nullptr){
            head = tail = newNode;
            return;
        }
        tail ->next = newNode;
        tail = newNode;

    }

    bool remove(int index) {

        if(index < 0 || head == nullptr) return false;
        
        if (index == 0){
           Node* temp = head;
           head = head-> next;
           if(head == nullptr) tail = nullptr;
           delete temp;
           return true; 
        }
        
        Node* prev = head;

        for(int i =0; i < index-1; i++){
            if (prev == nullptr) return false;
            prev = prev->next;

        }

        if (prev == nullptr || prev->next == nullptr) return false;

        Node* temp = prev-> next;
        prev->next = temp->next;
        if (temp == tail) tail = prev;
        delete temp;
        return true;
    }

    vector<int> getValues() {
        vector<int> values;
        Node* cur = head;
        while (cur != nullptr){
            values.push_back(cur->val);
            cur = cur->next;
        }

        return values;
        
    }
};
