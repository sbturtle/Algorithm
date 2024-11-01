#include<iostream>
#include<map>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second > b.second;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<int> vec;
	map<int, int> m;
	long long sum = 0;


	for (int i = 0; i < n; i++)
	{
		int num;		cin >> num;
		sum += num;
		m[num]++;
		vec.push_back(num);
	}

	vector<pair<int, int>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), cmp);

	sort(vec.begin(), vec.end());
	// 산술평균 : N개의 수들의 합을 N으로 나눈 값
	int tmp = round(sum / (float)n);
	cout << tmp << '\n';
	// 중앙값: N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
	cout << vec[n / 2] << '\n';

	// 최빈값 : N개의 수들 중 가장 많이 나타나는 값

	int num = v[0].first;
	int cnt = v[0].second;
	for (int i = 1; i < n; i++)
	{
		if (cnt == v[i].second) {
			num = v[i].first;
			break;
		}
		else
			break;
	}
	cout << num << '\n';
	// 범위 : N개의 수들 중 최댓값과 최솟값의 차이
	cout << abs(vec[n - 1] - vec[0]);

	return 0;
}