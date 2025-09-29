#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the 'taumBday' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER b
 *  2. INTEGER w
 *  3. INTEGER bc
 *  4. INTEGER wc
 *  5. INTEGER z
 */

long taumBday(int b, int w, int bc, int wc, int z) {
    long long bcCost = min((long long)bc, (long long)wc + z);
    long long wcCost = min((long long)wc, (long long)bc + z);

    return (long long)b * bcCost + (long long)w * wcCost;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        long b, w, bc, wc, z;
        cin >> b >> w >> bc >> wc >> z;

        long result = taumBday(b, w, bc, wc, z);
        cout << result << "\n";
    }

    return 0;
}
