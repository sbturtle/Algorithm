#include<bits/stdc++.h>
using namespace std;

int N;
void asd(int c, int a) {
	if (c > a) return;
	cout << '*';

	asd(c + 1, a);
}

void recursion(int a) {
	if (a > N) return;
	asd(1, a);
	cout << '\n';

	recursion(a + 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	int a = 1;
	recursion(a);
}