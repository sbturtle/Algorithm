#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int l;	cin >> l;
	string str;	cin >> str;

	long long result = 0;

	for (int i = 0; i < l; i++) {
		long long p = 1; // pow(31, i)
		for (int j = 0; j < i; j++) {
			p *= (long long int)31;
			p %= (long long int)1234567891;
		}
		result += ((long long)(str[i] - 96) * p) % 1234567891;
	}

	cout << result % 1234567891;

	return 0;
}