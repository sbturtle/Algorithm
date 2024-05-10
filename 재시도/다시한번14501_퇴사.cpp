#include <iostream>
#include <stack>
using namespace std;

int n;
int t[16];
int p[16];
int result;
int map[16];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> t[i] >> p[i];


	for (int i = 0; i <= n; i++)
	{
		map[i] = max(map[i], result);

		int nxt = i + t[i];
		if (nxt <= n) {
			map[nxt] = max(map[nxt], map[i] +p[i]);
		}
		result = max(result, map[i]);
	}


	cout << result;
	return 0;
}