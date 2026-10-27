// Rishabh Ranjan 25/DA/054

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s1, s2;
    cout <<"Enter String 1: ";
    cin >> s1;
    cout <<"Enter String 2: ";
    cin >> s2;
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    string lcs = "";
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcs = s1[i - 1] + lcs;
            i--;
            j--;
        } else if (dp[i - 1][j] >= dp[i][j - 1])
            i--;
        else
            j--;
    }
    cout <<"Length of LCS: " << dp[m][n] << endl << "LCS: " << lcs;
    return 0;
}
