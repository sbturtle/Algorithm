#include <iostream>
using namespace std;

bool s[246913]; 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 2; i * i <= 246912; i++) {
		if (!s[i]) {
			for (int j = i * i; j <= 246912; j += i) {
				s[j] = true;
			}
		}
	}

	while (true) {
		int n;
		cin >> n;
		if (n == 0)
			break;

		int cnt = 0;
		for (int i = n + 1; i <= n + n; i++)
			if (!s[i])
				cnt++;

		cout << cnt << '\n';
	}

	return 0;
}
