#include<bits/stdc++.h>
using namespace std;

int prec(char s) {
    if (s == '+') {
        return 0;
    } else if (s == '-') {
        return 0;
    } else if (s == '*') {
        return 1;
    } else if (s == '/') {
        return 1;
    }
    return -1;
}

int main() {
    cout << "hey this is an infix to postfix conversion code, try me XD" << endl;
    while(true) {
    cout << ">>";
    string s;
    cin >> s;
    int n = s.size();
    stack<char> store;
    string ans = "";
    for(int i = 0; i < n;i++) {
        char c = s[i];
        if(c == '(') {
            store.push('(');
        } else if (c == ')') {
            while(store.top() != '(') {
                ans+=store.top();
                store.pop();
            }
            store.pop();
        } else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
            || (c >= '0' && c <= '9')) {
            ans+=c;
        } else {
            if(store.size() == 0) {
                store.push(c);
            } else {
                while(prec(c) <= prec(store.top()) && store.size() != 0) {
                    ans+=store.top();
                    store.pop();
                    if(store.size() == 0) {
                        break;
                    }
                }
                store.push(c);
            }
        }
    }
    while(store.size() != 0) {
        ans+=store.top();
        store.pop();
    }
    cout << ans << endl;
}
}