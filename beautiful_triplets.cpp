#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the 'beautifulTriplets' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER d
 *  2. INTEGER_ARRAY arr
 */

int beautifulTriplets(int d, int arr[], int n) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        int first = arr[i];
        bool found_second = false;
        bool found_third = false;

        for (int j = i + 1; j < n; j++) {
            if (!found_second && arr[j] - first == d) {
                found_second = true;
            } else if (found_second && arr[j] - first == 2 * d) {
                found_third = true;
                break;
            }
        }

        if (found_second && found_third) count++;
    }

    return count;
}

int main() {
    int n, d;
    cin >> n >> d;

    int arr[10000]; // maximum n is usually 10^4

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = beautifulTriplets(d, arr, n);
    cout << result << "\n";

    return 0;
}
