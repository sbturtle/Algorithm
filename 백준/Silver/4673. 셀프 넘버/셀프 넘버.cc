#include <iostream>
#include <string>
using namespace std;

bool a[20'004];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int num, sum;

	for (int i = 0; i <= 10'000; i++) {
		num = i;
		sum = i;
		while (num != 0) {
			sum = sum + num % 10;
			num = num / 10;
		}
		a[sum] = true;
	}

	for (int i = 0; i <= 10'000; i++) {
		if (!a[i])
			cout << i << '\n';
	}

	return 0;
}