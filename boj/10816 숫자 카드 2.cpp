#include <iostream>
#include <algorithm>
using namespace std;

// ���� ���� -10,0000,000 ~ 10,0000,000 �̱⿡ �޸� ���ѿ� �ɸ��� �ʾ�
// ī���� ���ķ� ���� �ذ�
int a[20000004];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		a[num + 10000000]++;
	}

	int m;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int num;
		cin >> num;

		cout << a[num + 10000000] << ' ';
	}


	return 0;
}