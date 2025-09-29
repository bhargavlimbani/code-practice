#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the 'serviceLane' function below.
 *
 * The function is expected to return an array of integers.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D array of cases [t][2]
 */

int main() {
    int n, t;
    cin >> n >> t;

    int width[n]; // width of the lanes
    for (int i = 0; i < n; i++) {
        cin >> width[i];
    }

    for (int i = 0; i < t; i++) {
        int entry, exit;
        cin >> entry >> exit;

        int minWidth = width[entry];
        for (int j = entry + 1; j <= exit; j++) {
            if (width[j] < minWidth)
                minWidth = width[j];
        }

        cout << minWidth << "\n";
    }

    return 0;
}
