#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node (int data) {
        this -> data = data;
        this -> next = NULL;
    }
};

Node* takeInput() {
    Node* head = NULL;
    Node* tail = NULL;
    int data;
    cin >> data;
    while(data != -1) {
        Node *newNode = new Node(data);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void printLinkedList(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void insertatend(Node *head) {
    Node *temp = head;
    while(temp -> next != NULL) {
        temp = temp->next;
    }
    int data;
    cin >> data;
    Node *end = new Node(data);
    temp -> next = end;
}

void insertatbegin(Node **head) {
    int data;
    cin >> data;
    Node *begin = new Node(data);
    begin -> next = *head;
    *head = begin;
}

void insertatrandompos(Node*head) {
    int data,n;
    cin >> data >> n;
    Node *insert = new Node(data);
    Node *temp = head;
    if(n == 1) {
        insert -> next = head;
        head = insert;
        return;
    }
    if(n == 2) {
        insert -> next = head -> next;
        head -> next = insert;
        return;
    }
    while(n > 2) {
        temp = temp -> next;
        n--;
    }
    insert -> next = temp -> next;
    temp -> next = insert;
}

void getthemiddlepos(Node *head) {
    Node *slow = head;
    Node *fast = head;
    while(fast != NULL && fast -> next != NULL) {
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    cout << slow -> data << endl;
}
// hare tortoise algorithm
Node *findMid(Node *head) {
    Node *fast = head -> next;
    Node *slow = head;
    while(fast != NULL && fast -> next != NULL) {
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    return slow;
}

Node *merge(Node *left,Node *right) {
    if(left == NULL) {
        return right;
    }
    if(right == NULL) {
        return left;
    }
    Node *ans = new Node(-1);
    Node *temp = ans;
    while(left != NULL && right != NULL) {
        if(left -> data < right -> data) {
            temp -> next = left;
            temp = left;
            left = left -> next;
        } else {
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
    }
    while(left != NULL) {
            temp -> next = left;
            temp = left;
            left = left -> next;
    }
    while(right != NULL) {
            temp -> next = right;
            temp = right;
            right = right -> next;
    }
    ans = ans -> next;
    return ans;
}   

Node *mergesort(Node *head) {
    if(head == NULL || head -> next == NULL) {
        return head;
    }
    Node *mid = findMid(head);
    Node *left = head;
    Node *right = mid -> next;
    mid -> next = NULL;
    left = mergesort(left);
    right = mergesort(right);
    return merge(left,right);
}

Node* reverse(Node *head) {
    if(head == NULL || head -> next == NULL) {
        return head;
    }
    Node *smallAns = reverse(head -> next);
    Node *temp = smallAns;
    while(temp -> next != NULL) {
        temp = temp -> next;
    }
    temp -> next = head;
    head -> next = NULL;
    return smallAns;
}

int main() {
    // Node *head1 = takeInput();
    // Node *head2 = takeInput();/
    // Node *head2 = takeInput();
    // insertatend(head);
    // insertatbegin(&head);
    // insertatrandompos(head);
    // printLinkedList(head);
    // getthemiddlepos(head);
    // head1 = mergesort(head1);
    // head2 = mergesort(head2);
    // Node *head3 = merge(head1,head2);
    // head1 = reverse(head1);
    // printLinkedList(head1);
}