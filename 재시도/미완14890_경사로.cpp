#include <iostream>
using namespace std;
int map[101][101];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, l;
	cin >> n >> l;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}
	int result = 0;
	// ������ �˻�
	for (int i = 0; i < n; i++)
	{
		bool isAll = true;
		for (int j = 1; j < n; j++)
		{
			// ��� ������
			if (map[i][j] == map[i][j - 1]) continue;

			isAll = false;

			// �� ���� ���̰� 2�̻� ���� �Ǹ� ������ �Ұ���
			if (abs(map[i][j] - map[i][j - 1]) > 1)
				break;


			// �ٸ� ��� ��� ū ������,
			// ��� �۰� ���̰� �����������

			// ������ ���� �� ū ���
			if (map[i][j] < map[i][j - 1]) {
				for (int k = 1; k < l; k++) {
					int idx = j + k;
					if (idx >= n || map[i][idx - 1] != map[i][idx])					
						goto ASD;					
				}

				// ���θ� ������� ���
				j += l - 1;
				continue;
			}

			// ������ ���� �� ���� ���
			if (map[i][j] > map[i][j - 1]) {
				for (int k = 1; k <= l; k++) {
					int idx = j - k;
					if (idx < 0 || map[i][idx]!= map[i][idx - 1])
						goto ASD;
				}

				// ���θ� ������� ���
				j += l - 1;
				continue;
			}
		}

	ASD:
		if (isAll)
			result++;
	}

	return 0;
}