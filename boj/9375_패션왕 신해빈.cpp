#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;    cin >> t;
	while (t--) {
		int n;		cin >> n;
		map<string, int> m;
		int result = 1;
		for (int i = 0; i < n; i++) {
			string name, type;
			cin >> name >> type;
			m[type]++;
		}
		for (auto i : m)		
			result *= (i.second + 1);
		
		result -= 1;
		cout << result << '\n';

	}
	return 0;
}