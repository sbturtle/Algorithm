#include <iostream>
using namespace std;

// �ִ� ���� 888,855,064,897�̱⿡ int ������ ���
long long tr[101];
// DP�� �ذ�
// ��ȭ���� tr[i] = tr[i - 2] + tr[i - 3];
// ���� �ʱ���� 0���� 2���� ������
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	tr[0] = 0;
	tr[1] = 1;
	tr[2] = 1;

	for (int i = 3; i <= 100; i++)	{
		tr[i] = tr[i - 2] + tr[i - 3];
	}


	while (T--) {
		int n; cin >> n;
		cout << tr[n] << '\n';	
	}

	return 0;
}
