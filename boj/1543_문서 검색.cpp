#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string n, q;
	getline(cin, n);
	getline(cin, q);

	int qlen = q.length();

	int result = 0;
	int idx = n.find(q);
	while (idx != string::npos) {
		result++;
		idx = n.find(q, idx + qlen);
	}
	
	cout << result;
	return 0;
}