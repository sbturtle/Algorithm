#include <iostream>
#include <set>
using namespace std;

// 문제 번호 인덱스에 문제 나이도 값을 저장하는 배열
int ct[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 난이도를 기준으로 정렬
	set<pair<int, int>> ms;
	int N, M;

	cin >> N;
	while (N--) {
		int p, l;
		cin >> p >> l;
		ms.insert({ l,p });
		ct[p] = l;
	}

	cin >> M;
	while (M--) {
		string str;
		cin >> str;
		if (str == "add") {
			int p, l;
			cin >> p >> l;
			ms.insert({ l,p });
			ct[p] = l;

		}
		else if (str == "recommend") {
			int x; cin >> x;
			if (x == 1) {
				// 최댓값 출력
				pair<int, int> iter = *ms.rbegin();
				cout << iter.second << '\n';
			}
			else {
				// 최솟값 출력
				pair<int, int> iter = *ms.begin();
				cout << iter.second << '\n';
			}
		}
		else if (str == "solved") {
			// 특정 값 제거
			int p; cin >> p;

			// pair로 저장하고 있기 때문에 find 또한 pair로 찾아야 함..
			// 따라서 ct 배열을 통해 pair를 만듬
			ms.erase({ ct[p],p });
		}
	}

	return 0;
}