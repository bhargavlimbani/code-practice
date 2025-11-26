#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int minimumNumber(int n, string password) {
    bool lower = false, upper = false, digit = false, special = false;
    string sp = "!@#$%^&*()-+";

    for(char c : password) {
        if(islower(c)) lower = true;
        else if(isupper(c)) upper = true;
        else if(isdigit(c)) digit = true;
        else if(sp.find(c) != string::npos) special = true;
    }

    int missing = 0;
    if(!lower) missing++;
    if(!upper) missing++;
    if(!digit) missing++;
    if(!special) missing++;

    return max(missing, 6 - n);
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);
    int n = stoi(ltrim(rtrim(n_temp)));

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";
    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);
    s.erase(s.begin(), find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));
    return s;
}

string rtrim(const string &str) {
    string s(str);
    s.erase(find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end());
    return s;
}
