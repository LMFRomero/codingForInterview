#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;


int main() {
    stack<string> state;
    string current = "";
    string tmp_s;
    int q;
    int tmp_i;
    
    state.push(current);
    
    cin >> q;
    
    while (q--) {
        cin >> tmp_i;
        
        switch(tmp_i) {
            case 1:
                cin >> tmp_s;
                current.append(tmp_s);
                state.push(current);
                break;
            case 2:
                cin >> tmp_i;
                current = current.substr(0, current.length()-tmp_i);
                state.push(current);
                break;
            case 3:
                cin >> tmp_i;
                cout << current[tmp_i-1] << endl;
                break;
            case 4:
                state.pop();
                if (state.empty()) state.push(string(""));
                current = state.top();
                break;
            default:
                break;
        }
    } 
    return 0;
}
