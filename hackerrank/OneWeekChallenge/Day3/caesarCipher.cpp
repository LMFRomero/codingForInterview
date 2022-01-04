#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'caesarCipher' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER k
 */

string caesarCipher(string s, int k) {
    #define ALPHABETSIZE 26
    
    string ans = "";
    const int baseLower = (int)'a';
    const int baseUpper = (int)'A';
    
    k %= ALPHABETSIZE;
    
    for (char c : s) {
        int tmp = (int) c;
        int relativeLower = tmp-baseLower;
        int relativeUpper = tmp-baseUpper;
        
        if (relativeLower >= 0 and relativeLower < ALPHABETSIZE) {
            ans.push_back((char)((relativeLower+k)%ALPHABETSIZE)+baseLower);
        }
        else if (relativeUpper >= 0 and relativeUpper < ALPHABETSIZE) {
            ans.push_back((char)((relativeUpper+k)%ALPHABETSIZE)+baseUpper);            
        }
        else {
            ans.push_back(c);
        }
    }
    
    #undef ALPHABETSIZE
    
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string s;
    getline(cin, s);

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    string result = caesarCipher(s, k);

    fout << result << "\n";

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
