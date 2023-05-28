#include<bits/stdc++.h>
using namespace std;

class mystack {
    public:
    int n;
    int *arr;
    int last_elem;
    mystack() {
        n = 5;
        int *newarr = new int[5];
        arr = newarr;
        last_elem = 0;
    }
    void push(int data) {
        if(last_elem == n) {
            int *newarr = new int[2*n];
            for(int i = 0; i < n;i++) {
                newarr[i] = arr[i];
            }
            delete []arr;
            arr = newarr;
            n = n * 2;
        }
        arr[last_elem] = data;
        last_elem++;
    }
    int pop() {
        if(last_elem == 0) {
            return -1;
        }
        int target = arr[last_elem-1];
        int *newarr = new int[n-1];
        for(int i = 0;i < last_elem-1;i++) {
            newarr[i] = arr[i];
        }
        delete []arr;
        arr = newarr;
        n--;
        last_elem--;
        return target;
    }
    int sizeofstack() {
        return last_elem;
    }
    int top() {
        if(last_elem == 0) {
            return -1;
        }
        return arr[last_elem-1];
    }
    bool empty() {
        if(last_elem == 0) {
            return true;
        } else {
            return false;
        }
    }
    void print() {
        for(int i = last_elem-1; i >= 0;i--) {
            cout << arr[i] << endl;
        }
    }
};

int main() {
    mystack s;
    cout << "this is a dynamic stack made using arrays :)" << endl;
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