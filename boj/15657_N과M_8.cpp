#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n, m;
int map[10];
int isvis[10];

void func(int st, int cnt, string str) {

	if (cnt == m) {
		cout << str << '\n';
		return;
	}

	for (int i = st; i < n; i++)
		func(i, cnt + 1, str + to_string(map[i]) + ' ');
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> map[i];

	sort(map, map + n);

	func(0, 0, "");

	return 0;
}