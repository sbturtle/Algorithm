#include <bits/stdc++.h>
using namespace std;

int N;
int board[2200][2200];
int result[3];

bool check(int x, int  y, int n) {
	for (int i = x; i < x + n; i++)
		for (int j = y; j < y + n; j++)
			if (board[x][y] != board[i][j])
				return false;

	return true;
}

void func(int x, int y, int n) {
	if (check(x, y, n))
		result[board[x][y]]++;
	else {
		int newN = n / 3;

		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				func(x + (newN * i), y + (newN * j), newN);
	}
}

int main() {
	cout.tie(0); cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			int input;
			cin >> input;
			board[i][j] = ++input;
		}

	func(0, 0, N);

	for (int n : result)
		cout << n << '\n';
	return 0;
}