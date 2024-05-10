#include <iostream>
using namespace std;

int s[100001];
int r[100001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> s[i];

	// �ʱ��
	r[1] = s[1];

	// ��ȭ��
	// �� ������ ���� ���� �̸� ���س��� 
	// i���� j������ ���� (i������ ����) - (j-1������ ����) j���� ���ԵǾ�� ��
	// ���� �����Ͽ� ����
	for (int i = 2; i <= n; i++)
	{
		r[i] = r[i - 1] + s[i];
	}

	while (m--) {
		int i, j;
		cin >> i >> j;
		int result = r[j] - r[i - 1];
		cout << result << '\n';
	}

	return 0;
}