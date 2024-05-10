#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define st second
#define ed first
#define LL long long

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pair<LL, LL>> vec;
	for (int i = 0; i < n; i++)
	{
		int st, ed;
		cin >> st >> ed;
		vec.push_back({ ed,st });
	}
	
	// 종료 시간이 빠른 순으로 
	// 종료시간이 같다면 시작시간이 빠른 순으로 정렬
	sort(vec.begin(), vec.end());

	int t = 0;
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		// 가장 짧은 회의의 종료시간 보다 시작시간이 이른 경우 패스
		if (t > vec[i].st) continue;
		result++;
		t = vec[i].ed;
	}
	cout << result;
	return 0;
}
