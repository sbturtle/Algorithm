#include <iostream>
using namespace std;
#define LL long long

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int t_case = 0; t_case < t; t_case++)
	{
		LL a, b;
		cin >> a >> b;

		LL l = a + b;

		if (l)
			cout << "YES" << '\n';
		else
			cout << "no" << '\n';
	}

	return 0;
}