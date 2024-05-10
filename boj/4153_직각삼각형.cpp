#include <iostream>
using namespace std;

string isTr(int a, int b, int c) {
	return (c * c == a * a + b * b) ? "right" : "wrong";
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (1) {
		int a, b, c;
		cin >> a >> b >> c;

		if (!a && !b && !c) break;

		int m = max(max(a, b), c);

		if (a == m)
			cout << isTr(b, c, a) << '\n';
		else if (b == m)
			cout << isTr(a, c, b) << '\n';
		else
			cout << isTr(a, b, c) << '\n';

	}


	return 0;
}