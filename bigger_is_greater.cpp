#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the 'biggerIsGreater' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING w as parameter.
 */

string biggerIsGreater(string w) {
    int n = w.length();
    int i = n - 2;

    // Step 1: find first character from end which is smaller than next
    while (i >= 0 && w[i] >= w[i + 1]) i--;

    if (i < 0) return "no answer"; // already the last permutation

    // Step 2: find smallest character after i which is greater than w[i]
    int j = n - 1;
    while (w[j] <= w[i]) j--;

    // Step 3: swap
    swap(w[i], w[j]);

    // Step 4: reverse the substring after position i
    reverse(w.begin() + i + 1, w.end());

    return w;
}

int main() {
    int T;
    cin >> T;
    cin.ignore();

    for (int t = 0; t < T; t++) {
        string w;
        getline(cin, w);

        string result = biggerIsGreater(w);
        cout << result << "\n";
    }

    return 0;
}
