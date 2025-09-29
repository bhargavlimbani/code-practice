#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the 'chocolateFeast' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n  (money)
 *  2. INTEGER c  (cost per chocolate)
 *  3. INTEGER m  (wrappers needed for a free chocolate)
 */

int chocolateFeast(int n, int c, int m) {
    int chocolates = n / c;   // buy initial chocolates
    int wrappers = chocolates; // start with wrappers from bought chocolates

    while (wrappers >= m) {
        int free = wrappers / m;   // number of free chocolates
        chocolates += free;        // add to total
        wrappers = wrappers % m + free; // update wrappers
    }

    return chocolates;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, c, m;
        cin >> n >> c >> m;
        cout << chocolateFeast(n, c, m) << "\n";
    }

    return 0;
}
