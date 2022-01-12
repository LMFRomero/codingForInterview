#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'isBalanced' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isBalanced(string s) {
    bool balanced = true;
    stack<char> p;
    
    for (char tmp : s) {
        if (tmp == '(' || tmp == '[' || tmp == '{') {
            p.push(tmp);
        }
        else if (tmp == ')') {
            if (p.empty() || p.top() != '(') {
                balanced = false;
                break;
            }
            else {
                p.pop();
            }
        }
        else if (tmp == ']') {
            if (p.empty() || p.top() != '[') {
                balanced = false;
                break;
            }
            else {
                p.pop();
            }
        }
        else if (tmp == '}') {
            if (p.empty() || p.top() != '{') {
                balanced = false;
                break;
            }
            else {
                p.pop();
            }
        }
    }
    
    if (balanced == true) balanced = p.empty();
    
    return (balanced == true) ? string("YES") : string("NO");
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
