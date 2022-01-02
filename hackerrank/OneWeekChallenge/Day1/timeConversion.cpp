#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    string ans = "";
    string period = s.substr(8, 2);
    string tmp;
    
    tmp = s.substr(0, 2);
    
    if (period == "AM") {
        if (tmp == "12") {
            ans += "00";
        }
        else {
            ans += tmp;
        }
    }
    else if (period == "PM") {
        if (tmp == "12") {
            ans += tmp;
        }
        else {
            ans += to_string(stoi(tmp)+12);
        }
    }
    
    ans += s.substr(2, 6);
    
    return ans; 
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
