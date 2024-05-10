#include <iostream>
using namespace std;

int n;
int cards[1001];
int map[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> cards[i];

	// ��Ʈ��ŷ�� ���� �Ǵ��ϱ�? n^n XXXXX

	map[1] = cards[1];
	map[2] = max(cards[2], map[1] * 2);

	for (int i = 3; i <= n; i++)
	{
		// i���� ����ִ� ī������ �� ���
		int v = 0;

		// i���� ���� ���� ������ ī���ѵ��� �� ���
		for (int j = 1; j <= i; j++) {
			for (int k = j; k <= i; k++) {
				if (j + k == i) {						// i�� ���� ���Ϸ��� �ִ�ݾ׿� ��Ī�Ǵ� ī���� ����
					int tmp = map[j] + map[k];
					v = max(tmp, v);
				}
			}
		}
		map[i] = v;
	}

	cout << map[n];

	return 0;
}
