#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'climbingLeaderboard' function below.
 */
vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {
    vector<int> result;

    // Remove duplicates and sort descending
    vector<int> uniqueRanked;
    uniqueRanked.push_back(ranked[0]);

    for (int i = 1; i < ranked.size(); i++) {
        if (ranked[i] != ranked[i - 1]) {
            uniqueRanked.push_back(ranked[i]);
        }
    }

    int n = uniqueRanked.size();
    int index = n - 1; // Start from end for faster checking

    for (int score : player) {
        while (index >= 0 && score >= uniqueRanked[index]) {
            index--;
        }
        result.push_back(index + 2); // +2 because index is 0-based and rank starts from 1
    }

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string ranked_count_temp;
    getline(cin, ranked_count_temp);
    int ranked_count = stoi(ltrim(rtrim(ranked_count_temp)));

    string ranked_temp_temp;
    getline(cin, ranked_temp_temp);
    vector<string> ranked_temp = split(rtrim(ranked_temp_temp));
    vector<int> ranked(ranked_count);

    for (int i = 0; i < ranked_count; i++) {
        ranked[i] = stoi(ranked_temp[i]);
    }

    string player_count_temp;
    getline(cin, player_count_temp);
    int player_count = stoi(ltrim(rtrim(player_count_temp)));

    string player_temp_temp;
    getline(cin, player_temp_temp);
    vector<string> player_temp = split(rtrim(player_temp_temp));
    vector<int> player(player_count);

    for (int i = 0; i < player_count; i++) {
        player[i] = stoi(player_temp[i]);
    }

    vector<int> result = climbingLeaderboard(ranked, player);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];
        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";
    fout.close();
    return 0;
}

string ltrim(const string &str) {
    string s(str);
    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );
    return s;
}

string rtrim(const string &str) {
    string s(str);
    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );
    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;
    string::size_type start = 0, end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
    }

    tokens.push_back(str.substr(start));
    return tokens;
}
