#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int B[N];

    for (int i = 0; i < N; i++)
        cin >> B[i];

    int count = 0;

    for (int i = 0; i < N - 1; i++) {
        if (B[i] % 2 != 0) {
            B[i]++;
            B[i + 1]++;
            count += 2;
        }
    }

    if (B[N - 1] % 2 != 0)
        cout << "NO\n";
    else
        cout << count << "\n";

    return 0;
}
