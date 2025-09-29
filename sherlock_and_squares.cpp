#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the 'squares' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER a
 *  2. INTEGER b
 */

int squares(int a, int b) {
    int start = ceil(sqrt(a));   // smallest integer >= sqrt(a)
    int end = floor(sqrt(b));    // largest integer <= sqrt(b)

    if (end < start) return 0;
    return end - start + 1;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;

    while (q--) {
        int a, b;
        cin >> a >> b;

        int result = squares(a, b);
        fout << result << "\n";
    }

    fout.close();
    return 0;
}
