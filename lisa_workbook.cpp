#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the 'workbook' function below.
 *
 * n = number of chapters
 * k = max problems per page
 * arr = array of number of problems in each chapter
 */
int main() {
    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int special = 0;
    int page = 1;

    for (int chapter = 0; chapter < n; chapter++) {
        int problems = arr[chapter];

        for (int problem = 1; problem <= problems; problem++) {
            if (problem == page)
                special++;

            if (problem % k == 0 || problem == problems)
                page++;
        }
    }

    cout << special << "\n";

    return 0;
}
