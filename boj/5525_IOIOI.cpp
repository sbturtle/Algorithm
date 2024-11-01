#include <iostream>
#include <string>
using namespace std;

int n, m;
string s;

int solve() {
    int count = 0;
    int pc = 0;
    for (int i = 1; i < m - 1; ++i) {
        // "IOI" 패턴이 반복되는지 확인
        if (s[i - 1] == 'I' && s[i] == 'O' && s[i + 1] == 'I') {
            pc++;
            // N번 이상 반복되면 카운트를 증가
            if (pc >= n) {
                count++;
            }
            // "OI" 다음부터 다시 검사하기 위해 i를 한 칸 건너뜀
            i++;
        }
        else {
            // 패턴이 끊기면 초기화
            pc = 0;
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    cin >> s;

    cout << solve();
    return 0;
}
