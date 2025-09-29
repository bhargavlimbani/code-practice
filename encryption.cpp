#include <bits/stdc++.h>
using namespace std;

string encryption(string s) {
    string str = "";
    // Remove spaces
    for (char c : s) {
        if (c != ' ') str += c;
    }

    int L = str.length();
    int rows = floor(sqrt(L));
    int cols = ceil(sqrt(L));

    if (rows * cols < L) rows++;

    string result = "";

    // Read column by column
    for (int c = 0; c < cols; c++) {
        for (int r = 0; r < rows; r++) {
            int idx = r * cols + c;
            if (idx < L) result += str[idx];
        }
        if (c != cols - 1) result += ' ';
    }

    return result;
}

int main() {
    string s;
    getline(cin, s);

    string result = encryption(s);
    cout << result << "\n";

    return 0;
}
