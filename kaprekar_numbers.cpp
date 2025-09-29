#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the 'kaprekarNumbers' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER p
 *  2. INTEGER q
 */

void kaprekarNumbers(int p, int q) {
    bool found = false;

    for (int n = p; n <= q; n++) {
        long long sq = (long long)n * n;
        string s = to_string(sq);
        int len = s.length();

        string r_str = s.substr(len - to_string(n).length(), to_string(n).length());
        string l_str = (len - to_string(n).length() > 0) ? s.substr(0, len - to_string(n).length()) : "0";

        int l = stoi(l_str);
        int r = stoi(r_str);

        if (l + r == n) {
            cout << n << " ";
            found = true;
        }
    }

    if (!found) cout << "INVALID RANGE";
    cout << "\n";
}

int main() {
    int p, q;
    cin >> p >> q;

    kaprekarNumbers(p, q);

    return 0;
}
