#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node(int data) {
        this -> data = data;
        next = NULL;
    }
};

class myqueue {
    public:
    node *head = NULL;
    node *tail = NULL;
    void enqueue(int data) {
        if(head == NULL) {
            node *newnode = new node(data);
            head = newnode;
            tail = newnode;
        } else {
            node *newnode = new node(data);
            tail -> next = newnode;
            tail = newnode;
        }
    }
    int dequeue() {
        if(head == NULL) {
            return -1;
        }
        int data = head -> data;
        node *temp = head -> next;
        delete head;
        if(head == tail) {
            head = temp;
            tail = temp;
        } else {
            head = temp;
        }
        return data;
    }
    void print() {
        node *temp = head;
        while(temp != NULL) {
            cout << temp -> data << " ";            
            temp = temp -> next;
        }
        cout << endl;
    }
};

int main() {
    myqueue myq;
    while(true) {
        cout << ">>";
        string s;
        cin >> s;
        if(s == "enq") {
            int data;
            cin >> data;
            myq.enqueue(data);
        } else if (s == "deq") {
            int mem = myq.dequeue();
            if(mem == -1) {
                cout << "the queue seems to be empty :(" << endl;
            } else {
                cout << mem << endl;
            }
        } else if (s == "print") {
            myq.print();
        } else {
            cout << "try enq,deq,print :)" << endl;
        }
    }
}