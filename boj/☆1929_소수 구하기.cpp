#include <iostream>
#include <cmath>
using namespace std;

int m, n;
int arr[1000001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;
	// �����佺�׳׽��� ü
	// ���� https://donggoolosori.github.io/2020/10/16/eratos/
	// �ִ� ���� ���� �����ٱ����� ������ ����� �����ϸ�
	// ���� ������ �Ҽ�

	for (int i = 2; i <= n; i++)
		arr[i] = i;

	// 2���� �ִ� ���� �����ٱ���
	for (int i = 2; i <= sqrt(n); i++)
	{
		// 0�̸� �̹� �Ҽ��� �ƴ�
		if (!arr[i])	continue;

		// ������� ����.
		for (int j = i * i; j <= n; j += i)
			arr[j] = 0;
	}

	for (int i = m; i <= n; i++)
	{
		// 0�̸� �Ҽ��� �ƴ�
		if (!arr[i])	continue;

		cout << arr[i] << '\n';
	}
	return 0;
}