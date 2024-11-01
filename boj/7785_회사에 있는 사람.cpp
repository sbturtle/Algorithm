#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	unordered_set<string> s;

	for (int i = 0; i < n; i++)
	{
		string name, type;
		cin >> name >> type;
		if (type == "enter") {
			s.insert(name);
		}
		else {
			s.erase(name);
		}
	}
	vector<string> vec(s.begin(), s.end());

	sort(vec.begin(), vec.end(), greater<string>());

	for (string str : vec)
		cout << str << '\n';

	return 0;
}