#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

string happyLadybugs(string b) {

    int freq[26] = {0};
    int emptyCount = 0;

    // Count frequency of each color & blanks
    for (char c : b) {
        if (c == '_') emptyCount++;
        else freq[c - 'A']++;
    }

    // If no blanks -> must already be happy
    if (emptyCount == 0) {
        for (int i = 0; i < b.size(); i++) {
            if ((i == 0 || b[i] != b[i - 1]) &&
                (i == b.size() - 1 || b[i] != b[i + 1])) {
                return "NO";
            }
        }
        return "YES";
    }

    // If blanks exist -> check if any color occurs only once
    for (int i = 0; i < 26; i++) {
        if (freq[i] == 1) return "NO";
    }

    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string g_temp;
    getline(cin, g_temp);

    int g = stoi(ltrim(rtrim(g_temp)));

    for (int g_itr = 0; g_itr < g; g_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string b;
        getline(cin, b);

        string result = happyLadybugs(b);

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
