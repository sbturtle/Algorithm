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
	
	// ���� �ð��� ���� ������ 
	// ����ð��� ���ٸ� ���۽ð��� ���� ������ ����
	sort(vec.begin(), vec.end());

	int t = 0;
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		// ���� ª�� ȸ���� ����ð� ���� ���۽ð��� �̸� ��� �н�
		if (t > vec[i].st) continue;
		result++;
		t = vec[i].ed;
	}
	cout << result;
	return 0;
}
