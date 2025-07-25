#include <iostream>
#include <vector>
using namespace std;

vector<int> compareTriplets(vector<int> a, vector<int> b) {
    int alice_score = 0;
    int bob_score = 0;

    for (int i = 0; i < 3; i++) {
        if (a[i] > b[i]) {
            alice_score++;
        } else if (a[i] < b[i]) {
            bob_score++;
        }
        // If a[i] == b[i], no points are awarded
    }

    return {alice_score, bob_score};
}

int main() {
    vector<int> a(3), b(3);

    // Input
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < 3; i++) {
        cin >> b[i];
    }

    // Compare and get result
    vector<int> result = compareTriplets(a, b);

    // Output
    cout << result[0] << " " << result[1] << endl;

    return 0;
}
