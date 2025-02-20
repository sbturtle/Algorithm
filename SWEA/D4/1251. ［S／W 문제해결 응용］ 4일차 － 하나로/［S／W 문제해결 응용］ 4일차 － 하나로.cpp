#include<iostream>
#include<algorithm>
#include<vector>
#include <array>
using namespace std;
#define  LL long long
using tu = array< LL, 3>;

LL x[1004];
LL y[1004];

int parent[1004];

int find(int x) {
	if (parent[x] < 0) return x;
	return parent[x] = find(parent[x]);
}

bool isInclude(int& u, int& v) {
	u = find(u);
	v = find(v);

	if (u == v)
		return true;
	return false;
}

bool uni(int u, int v) {
	if (isInclude(u, v))
		return false;
	if (parent[u] > parent[v])
		swap(u, v);
	parent[u]--;
	parent[v] = u;

	return true;
}

LL square(LL x) {
	return x * x;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		LL result = 0;
		int n;		cin >> n;

		fill(parent, parent + n, -1);
		for (int i = 0; i < n; i++)
			cin >> x[i];
		for (int i = 0; i < n; i++)
			cin >> y[i];
		vector <tu> vec;

		long double e;		cin >> e;
		for (LL i = 0; i < n; i++)
			for (LL j = i + 1; j < n; j++)
				vec.push_back({ (square(abs(x[i] - x[j])) + square(abs(y[i] - y[j]))), i, j });

		sort(vec.begin(), vec.end());

		for (auto l : vec)
		{
			if (uni(l[1], l[2]))
				result += l[0];
		}

		cout.precision(0);
		cout << fixed;
		cout << '#' << test_case << ' ' << result * e << '\n';
	}
	return 0;
}
