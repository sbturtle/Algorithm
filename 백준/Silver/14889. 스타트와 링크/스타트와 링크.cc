#include <iostream>
#include <cmath>
using namespace std;

int n;
int v[21][21];
bool isUsed[21];
int result = 1000000;

void func(int start, int k) {
	if (k == n / 2) {
		int st = 0;
		int li = 0;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				if (isUsed[i] && isUsed[j])
					st += v[i][j];
				else if (!isUsed[i] && !isUsed[j])
					li += v[i][j];
			}

		if (result > abs(st - li))
			result = abs(st - li);
		return;
	}

	for (int i = start; i < n; i++)
	{
		if (!isUsed[i]) {
			isUsed[i] = true;
			func(i + 1, k + 1);
			isUsed[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> v[i][j];

	func(0, 0);

	cout << result;
	return 0;
}