#include <iostream>
#include <vector>
using namespace std;

#define x first
#define y second

// ġŲ���� ��ǥ�� ����ǥ�� ����
// ġŲ���� m���� ����� ���� ����
// �ش� ����� ġŲ�Ÿ��� ���ϰ�, �ش� �Ÿ��� �ּҰ����� Ȯ��

int n, m;
vector<pair<int, int>> hMap;	// �� ��ġ
vector<pair<int, int>> ckMap;	// ġŲ�� ��ġ
int result = 1000000000;

void func(int start, int k, vector<bool>& isUsed) {
	if (k == m) {
		int sumDis = 0;
		for (auto h : hMap) {
			// �� ���� �ּҰŸ��� ġŲ�Ÿ�
			int min = 1000000000;
			for (int i = 0; i < ckMap.size(); i++)
			{
				if (isUsed[i]) {
					auto ck = ckMap[i];
					int dis = abs(h.x - ck.x) + abs(h.y - ck.y);
					if (min > dis)
						min = dis;
				}
			}
			sumDis += min;
		}
		if (result > sumDis)
			result = sumDis;
	}

	for (int i = start; i < ckMap.size(); i++)
	{
		if (!isUsed[i])
		{
			isUsed[i] = true;
			func(i + 1, k + 1, isUsed);
			isUsed[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int num;
			cin >> num;

			if (num == 1)
				hMap.push_back({ i,j });
			if (num == 2)
				ckMap.push_back({ i,j });
		}
	}

	// ö������ ���� ġŲ��
	vector<bool> isUsed(ckMap.size(), false);

	func(0, 0, isUsed);

	cout << result;
	return 0;
}