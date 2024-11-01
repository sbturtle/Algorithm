#include <iostream>
#include <string>
using namespace std;

int n, m;
string s;

int solve() {
    int count = 0;
    int pc = 0;
    for (int i = 1; i < m - 1; ++i) {
        // "IOI" ������ �ݺ��Ǵ��� Ȯ��
        if (s[i - 1] == 'I' && s[i] == 'O' && s[i + 1] == 'I') {
            pc++;
            // N�� �̻� �ݺ��Ǹ� ī��Ʈ�� ����
            if (pc >= n) {
                count++;
            }
            // "OI" �������� �ٽ� �˻��ϱ� ���� i�� �� ĭ �ǳʶ�
            i++;
        }
        else {
            // ������ ����� �ʱ�ȭ
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
