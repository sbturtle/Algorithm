#include <iostream>
using namespace std;

int wine[10001];
int map[10001][3];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> wine[i];

	// �ʱ��
	// ó���� �������� ���� ���� �ֱ� ������ 1��° �����ϴ� ���
	// 2��°�� ó�� �����ϴ� ��� ���� ����ؼ� �ʱ�� �ۼ��� �ʿ��� ��
	map[0][1] = wine[0];	// 1��°�� ó�� �����ϴ� ���
	map[1][2] = map[1 - 1][1] + wine[1];

	map[1][1] = wine[1];	// 2��°�� ó�� �����ϴ� ���
	// �������� �ʾ��� ��� ������ �ִ밪�� ���� ��
	map[1][0] = max(map[1 - 1][1], map[1 - 1][2]);

	int result = max(max(map[0][1], map[1][1]), map[1][2]);
	// ��ȭ��
	// map[i][0] = max(map[i-2][0],map[i-2][1]) + wine[i]
	// map[i][1] = map[i-1][0] + wine[i]
	for (int i = 2; i < n; i++)
	{
		// i ��°�� �������� �ʾ��� ��� ������ �ִ밪�� ���� ��
		map[i][0] = max(map[i - 1][0], max(map[i - 1][1], map[i - 1][2]));

		// i ��°�� 1ȸ ������ ��� 2ĭ ���� 1ȸ �Ǵ� 2ȸ ���� �� �ִ밪(�������� �ʾ��� ����� �ִ밪)�� ����
		map[i][1] = map[i - 1][0] + wine[i];
		// i ��°�� 2ȸ ������ ��� ���� ���� ����
		map[i][2] = map[i - 1][1] + wine[i];

		int tmp = max(map[i][1], map[i][2]);
		if (result < tmp)
			result = tmp;
	}

	cout << result;

	return 0;
}