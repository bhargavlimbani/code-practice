#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the 'organizingContainers' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts 2D_INTEGER_ARRAY container as parameter.
 */

string organizingContainers(int n, long long container[][100]) {
    long long rowSum[100] = {0};
    long long colSum[100] = {0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            rowSum[i] += container[i][j];
            colSum[j] += container[i][j];
        }
    }

    sort(rowSum, rowSum + n);
    sort(colSum, colSum + n);

    for (int i = 0; i < n; i++) {
        if (rowSum[i] != colSum[i]) return "Impossible";
    }
    return "Possible";
}

int main() {
    int q;
    cin >> q;

    for (int t = 0; t < q; t++) {
        int n;
        cin >> n;
        long long container[100][100]; // max constraints 100x100

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> container[i][j];
            }
        }

        string result = organizingContainers(n, container);
        cout << result << "\n";
    }

    return 0;
}
