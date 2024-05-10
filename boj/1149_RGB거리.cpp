#include <iostream>
using namespace std;
int r[1004];
int g[1004];
int b[1004];

// r�� ĥ�� ���, g�� ĥ�� ���, b�� ĥ�� ��츦 ��� ����
// ���� 1000���� ���� 3���� ��� [1001][4]���� ����(1�� ���� �ε����� ���)
int arr[1001][4];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> r[i] >> g[i] >> b[i];

	// �ʱ��
	// ������ ���� ���� ��ȭ���� ����Ǳ⿡ 1��° �ε����� �ʱ� ����
	arr[1][1] = r[1];
	arr[1][2] = g[1];
	arr[1][3] = b[1];

	// ��ȭ��
	// ���� i��°�� R�� ĥ�Ϸ��� i-1��°�� R�� �ƴ� �ٸ� ������ ĥ�ؾ� ��.
	// �ٸ� �� ��� ����.
	// 3������ ��츦 ��� ����
	for (int i = 2; i <= n; i++)
	{
		arr[i][1] = min(arr[i - 1][2], arr[i - 1][3]) + r[i];
		arr[i][2] = min(arr[i - 1][1], arr[i - 1][3]) + g[i];
		arr[i][3] = min(arr[i - 1][1], arr[i - 1][2]) + b[i];
	}

	// �� ������ �� �� �ּڰ� ���
	cout << min(arr[n][1], min(arr[n][2], arr[n][3]));

	return 0;
}