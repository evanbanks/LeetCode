struct Node {
    int val;
    Node* next = nullptr;
    Node(int val, Node* n) : val {val}, next {n} {};
};


class MinStack {
public:
    MinStack() = default;
    
    ~MinStack() {
        while (head){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    
    void push(int val) {
        Node* temp = new Node(val,head);
        if (mins.empty() || val < mins.top()->val) mins.push(temp);
        head = temp;
    }
    
    void pop() {
        Node* temp = head;
        if (mins.top() == temp) mins.pop();
        head = head->next;
        delete temp;
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        return mins.top()->val;
    }
private:
    Node* head = nullptr;
    std::stack<Node*> mins {};
};
