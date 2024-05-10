// ������������ ������ ����� ���� ���� 1ȸ�� ����ϴ� ����
// n���� ������ ���� �迭�� ����� ���� �� ���� ���� 1ȸ ����ϴ� ������ �����ϴ�,
// ���� ������ 2000 �����̰�, 1ȸ ����̸� ī���� ������ ����ϴ� ���� ��
// ���ƺ��� �ش� ������� �ڵ� ����
// ���밪�� �����̱⿡ 1000�� ���� �ְ� ���� ����� ä����

#include <iostream>
#include <algorithm>
using namespace std;

bool a[2001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		num += 1000;
		a[num] = true;
	}

	for (int i = 0; i < 2001; i++)
	{
		if (a[i]) {
			cout << i - 1000 << ' ';
		}
	}

	return 0;
}