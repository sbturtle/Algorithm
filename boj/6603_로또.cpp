#include <iostream>
using namespace std;

int n;		// ��ȣ ����

int s[15];		// ��ȣ �迭
int res[7];		// ���� �迭

bool isUsed[15];	// ��ȣ �湮 ����

void func(int start, int depth) {
	if (depth == 6) {
		for (int i = 0; i < 6; i++)
			cout << res[i] << " ";

		cout << "\n";
		return;
	}

	for (int i = start; i < n; i++)
	{
		if (!isUsed[i]) {
			// ���̰� 0�̰ų�(0�̸� ������ ����)
			// ���� ���� ���� ������ Ŭ ���
			if (depth != 0 && res[depth - 1] >= s[i])
				continue;

			isUsed[i] = true;
			res[depth] = s[i];
			func(start + 1, depth + 1);
			isUsed[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		cin >> n;
		if (n == 0) break;

		for (int i = 0; i < n; i++)
			cin >> s[i];

		func(0, 0);
		cout << "\n";
	}

	return 0;
}