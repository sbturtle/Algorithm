#include <iostream>
using namespace std;

int n, m;
int arr[201][201];
int result = 0;
void func(int old, int num, int c) {
	if (c == 3) {
		result++;
		return;
	}

	for (int i = num + 1; i <= n; i++)
	{
		if (arr[num][i] || arr[old][num] || arr[old][i]) continue;
		func(num, i, c + 1);
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	func(0, 0, 0);

	cout << result;
	return 0;
}