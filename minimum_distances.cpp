#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the 'minimumDistances' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

int minimumDistances(int a[], int n) {
    int minDist = n + 1; // initialize with large value

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                int dist = j - i;
                if (dist < minDist) minDist = dist;
            }
        }
    }

    if (minDist == n + 1) return -1; // no such pair found
    return minDist;
}

int main() {
    int n;
    cin >> n;

    int a[1000]; // adjust size according to constraints

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int result = minimumDistances(a, n);
    cout << result << "\n";

    return 0;
}
