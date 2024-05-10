#include<bits/stdc++.h>
using namespace std;

int N;
void space(int b, int a)
{
	if (b == a) return;
	cout << ' ';
	space(b-1, a);
}

void star(int b, int a)
{
	if (b > a) return;
	cout << '*';
	star(b + 1, a);
}

void recursion(int a)
{
	if (a > N) return;

	space(N, a);
	star(1, a);
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