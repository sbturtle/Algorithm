#include<iostream>
using namespace std;

int dwarfs[9];
int liars = -100;

void findLiars() {
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (dwarfs[i] + dwarfs[j] == liars) {
				dwarfs[i] = 0;
				dwarfs[j] = 0;

				return;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 9; i++) {
		cin >> dwarfs[i];
		liars += dwarfs[i];
	}

	findLiars();

	for (int dwarf : dwarfs) {
		if (dwarf == 0)
			continue;
		cout << dwarf << '\n';
	}

	return 0;
}