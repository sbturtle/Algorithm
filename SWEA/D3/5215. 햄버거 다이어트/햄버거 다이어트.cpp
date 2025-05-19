#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        int n, l;
        cin >> n >> l;
        int result = 0;

        int kcal[21] = { 0, };
        int score[21] = { 0, };
        for (int i = 1; i <= n; i++) {
            cin >> score[i] >> kcal[i];
        }
        vector<vector<int>> dp(n + 1, vector<int>(l + 1, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= l; ++j) {
                if (j < kcal[i]) {
                    dp[i][j] = dp[i - 1][j];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - kcal[i]] + score[i]);
                }
            }
        }
        result = dp[n][l];
        cout << '#' << test_case << ' ' << result << '\n';
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}