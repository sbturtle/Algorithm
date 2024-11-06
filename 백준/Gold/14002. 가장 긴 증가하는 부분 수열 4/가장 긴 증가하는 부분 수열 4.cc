#include <iostream>
#include <map>
#include <vector>
using namespace std;

int n;
int ml;			// 가장 긴 수열의 길이
int biggest;	// 가장 긴 수열의 마지막 숫자
int dp[1001];
map<int, vector<int>> mp;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (size_t i = 0; i < n; i++) {
		int num;
		cin >> num;

		int leng = 0;		// 현재까지 가장 긴 수열의 길이
		int big = 0;		// 현재까지 가장 긴 수열의 마지막 숫자

		// 입력받은 숫자보다 작은 수 중에
		// 가장 긴 증가하는 수열 찾기
		for (int j = 1; j < num; j++) {
			if (dp[j] > leng) {
				leng = dp[j];
				big = j;
			}
		}
		mp[num] = mp[big];
		mp[num].push_back(num);
		dp[num] = ++leng;

		if (leng > ml) {
			ml = leng;
			biggest = num;
		}
	}

	cout << ml << '\n';
	for (int num : mp[biggest])
		cout << num << ' ';

	return 0;
}