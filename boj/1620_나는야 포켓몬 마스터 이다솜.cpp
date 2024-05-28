#include <iostream>
#include <unordered_map>
#include <string>
#include <cctype>
using namespace std;

unordered_map<string, int> nameToIdx;
string idxToName[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m; cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		string name;		cin >> name;
		idxToName[i] = name;
		nameToIdx[name] = i;
	}

	while (m--) {
		string sol;
		cin >> sol;
		if (isdigit(sol[0]))
			cout << idxToName[stoi(sol)] << '\n';
		else
			cout << nameToIdx[sol] << '\n';
	}

	return 0;
}