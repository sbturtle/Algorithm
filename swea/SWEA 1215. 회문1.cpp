#include<iostream>
using namespace std;

string map[9];
int main(int argc, char** argv)
{
    int test_case;
    int T = 10;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int n; cin >> n;
        for (int i = 1; i <= 8; i++)
            cin >> map[i];

        int result = 0;

        for (int i = 1; i <= 8; i++) {
            for (int j = 1; j <= 8; j++) {
                if (j + n > 8) break;
                bool isP = true;
                for (int k = 0; k < n / 2; k++) {
                    if (map[i][j + k] != map[i][(j + n) - k]) {
                        isP = false;
                        break;
                    }
                }
                if (isP)
                {
                    for (int k = j; k < j + n; k++)
                        cout << map[i][k];
                    cout << '\n';
                    result++;
                }

            }
        }
        for (int i = 1; i <= 8; i++) {
            for (int j = 1; j <= 8 - n; j++) {
                bool isP = true;
                for (int k = 0; k < n / 2; k++) {
                    if (map[j + k][i] != map[(j + n) - k][i]) {
                        isP = false;
                        break;
                    }
                }
                if (isP)
                {
                    for (int k = j; k < j + n; k++)
                        cout << map[k][i];
                    cout << '\n';
                    result++;
                }
            }
        }

        cout << '#' << test_case << ' ' << result << '\n';
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}