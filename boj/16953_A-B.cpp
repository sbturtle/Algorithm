#include<iostream>
#define MAX_VALUE 1000000000
using namespace std;

int a, b;
int result = MAX_VALUE;
void func(long long nxt, int cnt) {
	if (nxt > b)
		return;
	if (nxt == b) {
		result = min(result, cnt);
		return;
	}
	cnt++;
	func(nxt * 2, cnt);
	func((nxt * 10) + 1, cnt);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b;

	func(a, 0);
	if (result == MAX_VALUE)
		cout << -1;
	else
	cout << result + 1;
	return 0;
}
