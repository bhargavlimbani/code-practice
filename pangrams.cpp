#include <bits/stdc++.h>
using namespace std;

string pangrams(string s) {
    vector<bool> seen(26, false);
    for (char c : s) {
        if (isalpha(c)) {
            c = tolower(c);
            seen[c - 'a'] = true;
        }
    }
    for (bool x : seen) {
        if (!x) return "not pangram";
    }
    return "pangram";
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
