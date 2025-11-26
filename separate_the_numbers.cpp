#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

string addOne(string num) {
    int carry = 1;
    for (int i = num.size() - 1; i >= 0 && carry; i--) {
        int x = num[i] - '0' + carry;
        num[i] = char('0' + (x % 10));
        carry = x / 10;
    }
    if (carry) num.insert(num.begin(), '1');
    return num;
}

bool startsWith(const string &s, const string &prefix, int pos) {
    if (pos + prefix.size() > s.size()) return false;
    return s.compare(pos, prefix.size(), prefix) == 0;
}

void separateNumbers(string s) {
    int n = s.size();
    for (int len = 1; len <= n / 2; len++) {
        string start = s.substr(0, len);
        string nextNum = start;
        int pos = 0;

        while (true) {
            if (!startsWith(s, nextNum, pos)) break;
            pos += nextNum.size();
            nextNum = addOne(nextNum);
            if (pos == n) {
                cout << "YES " << start << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

int main() {
    string q_temp;
    getline(cin, q_temp);
    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);
        separateNumbers(s);
    }

    return 0;
}

string ltrim(const string &str) {
    string s(str);
    s.erase(s.begin(), find_if(s.begin(), s.end(), not1(ptr_fun<int,int>(isspace))));
    return s;
}

string rtrim(const string &str) {
    string s(str);
    s.erase(find_if(s.rbegin(), s.rend(), not1(ptr_fun<int,int>(isspace))).base(), s.end());
    return s;
}
