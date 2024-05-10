#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> all = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> vec;

	int m;
	cin >> m;

	while (m--)
	{
		string action;
		int x;

		cin >> action;


		if (action == "add")
		{
			cin >> x;

			auto cur = find(vec.begin(), vec.end(), x);

			if (cur != vec.end()) continue;

			vec.push_back(x);
		}
		else if (action == "remove")
		{
			cin >> x;

			auto cur = find(vec.begin(), vec.end(), x);

			if (cur == vec.end()) continue;

			vec.erase(cur);
		}
		else if (action == "check")
		{
			cin >> x;

			auto cur = find(vec.begin(), vec.end(), x);

			cout << (cur != vec.end() ? '1' : '0') << '\n';
		}
		else if (action == "toggle")
		{
			cin >> x;

			auto cur = find(vec.begin(), vec.end(), x);

			if (cur != vec.end())
				vec.erase(cur);
			else
				vec.push_back(x);

		}
		else if (action == "all")
		{
			vec.clear();
			vec = all;
		}
		else
		{
			vec.clear();
		}

	}


	return 0;
}