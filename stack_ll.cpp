#include<bits/stdc++.h>
using namespace std;

class node {
    public:
    int data;
    node *next;
    node(int data) {
        this -> data = data;
        next = NULL;
    }
};

class mystack {
    public:
    node* head = NULL;
    void push(int data) {
        if(head == NULL) {
            node *newnode = new node(data);
            head = newnode;
        } else {
            node *newnode = new node(data); 
            newnode -> next = head;
            head = newnode;
        }
    }
    int pop() {
        if (head == NULL) {
            return -1;
        }
        int data = head -> data;
        node *temp = head -> next;
        delete head;
        head = temp;
        return data;
    }
    int sizeofstack() {
        node *temp = head;
        int count = 0;
        while(temp != NULL) {
            count++;
        }
        return count;
    }
    int top() {
        if(head == NULL) {
            return -1;
        }
        return head -> data;
    }
    bool empty() {
        if(head == NULL) {
            return true; 
        } else {
            return false;
        }
    }
    void print() {
        node* temp = head;
        while(temp != NULL) {
            cout << temp -> data << endl;
            temp = temp -> next;
        }
    }
};

int main() {
    mystack s;
    cout << "this is a dynamic stack made using linked-list :)" << endl;
    while(true) {
        cout << ">>";
        string com;
        cin >> com;
        if(com == "push") {
            int mem;
            cin >> mem;
            s.push(mem);
        } else if (com == "pop") {
            int mem = s.pop();
            if(mem == -1) {
                cout << "the stack is empty" << endl;
            } else {
                cout << mem << endl;
            }
        } else if (com == "size") {
            cout << s.sizeofstack() << endl;
        } else if(com == "top") {
            int mem = s.top();
            if(mem == -1) {
                cout << "the stack is empty right now !" << endl;
            } else {
                cout << s.top() << endl;
            }
        } else if (com == "empty") {
            if(s.empty()) {
                cout << "YES the stack is empty" << endl;
            } else {
                cout << "the stack is not empty" << endl;
            }
        } else if (com == "print") {
            s.print();
        } else {
            cout << "the available commands are push (integer), pop, size,top,empty and print. Please use any one of them. !! :)" << endl;
        }
    }
}