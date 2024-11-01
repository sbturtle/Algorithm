#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;	cin >> n >> k;
	vector<pair<int, int>> vec;

	for (int i = 0; i < n; i++)
	{
		int m, v; cin >> m >> v;
		vec.push_back({ v,m });
	}
	sort(vec.begin(), vec.end());

	multiset<int> bags;

	for (int i = 0; i < k; i++)
	{
		int tmp; cin >> tmp;
		bags.insert(tmp);
	}
	// 가장 작은 가방부터 검사해서 확인
	long long result = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		auto bag = bags.lower_bound(vec[i].second);
		if (bag == bags.end())
			continue;

		result += vec[i].first;
		bags.erase(bag);
	}
	cout << result;
	return 0;
}