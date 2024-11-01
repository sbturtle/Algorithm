#include <iostream>
using namespace std;

int node[27][2];

// mid -> left -> right
void fore(int c) {
	cout << (char)('A' + c - 1);
	if (node[c][0] != 0)
		fore(node[c][0]);
	if (node[c][1] != 0)
		fore(node[c][1]);
}
// left -> mid -> right
void mid(int c) {
	if (node[c][0] != 0)
		mid(node[c][0]);
	cout << (char)('A' + c - 1);
	if (node[c][1] != 0)
		mid(node[c][1]);
}
// left -> right -> mid 
void pre(int c) {
	if (node[c][0] != 0)
		pre(node[c][0]);
	if (node[c][1] != 0)
		pre(node[c][1]);
	cout << (char)('A' + c - 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		char p, l, r;
		cin >> p >> l >> r;
		if (l != '.')
			node[p - 'A' + 1][0] = l - 'A' + 1;
		if (r != '.')
			node[p - 'A' + 1][1] = r - 'A' + 1;
	}

	fore(1);
	cout << '\n';
	mid(1);
	cout << '\n';
	pre(1);

	return 0;
}