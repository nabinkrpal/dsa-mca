#include <iostream>
using namespace std;

int getLength(char text[]) {
    int length = 0;
    while (text[length] != '\0') {
        length++;
    }
    return length;
}

int longestCommonSubsequence(char text1[], char text2[]) {
    int m = getLength(text1);
    int n = getLength(text2);
    int dp[100][100] = {0}; 

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

int main() {
    char text1[100], text2[100]; 

    cout << "Enter the first string: ";
    cin >> text1;
    cout << "Enter the second string: ";
    cin >> text2;

    int lcsLength = longestCommonSubsequence(text1, text2);
    cout << "Length of Longest Common Subsequence: " << lcsLength << endl;

    return 0;
}
