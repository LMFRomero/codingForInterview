#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

stack<int> f;
stack<int> b;

void back2front() {
    while (b.empty() == false) {
        f.push(b.top());
        b.pop();
    } 
}

void enqueue(int n) {
    b.push(n);
}

void dequeue() {
    if (f.empty()) back2front();
    f.pop();
}

void printFront() {
    if (f.empty()) back2front();
    cout << f.top() << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int q, tmp;
    
    cin >> q;
    
    while (q--) {
        cin >> tmp;
        
        switch(tmp) {
            case 1:
                cin >> tmp;
                enqueue(tmp);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                printFront();
                break;
        }
    }
    
    return 0;
}
