#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

// map의 second 값인 순서를 기준으로 정렬을 해야하기에 compare함수 정의
bool compare(const pair<string, int> a, const pair<string, int> b) {
	return a.second < b.second;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	unordered_map<string, int> map;
	vector<pair<string, int>> vec;

	int k, l;
	cin >> k >> l;

	// 앞에 이미 등록되어있더라도, index 값을 덮어씌우면 후순위로 이동
	for (int i = 0; i < l; i++)
	{
		string n;	cin >> n;
		map[n] = i;
	}

	// unordered_map은 정렬이 되어있지 않기에, 정렬을 위해 vector 배열에 재정의
	for (auto m : map)
		vec.push_back(m);

	sort(vec.begin(), vec.end(), compare);

	// 만약, 최대 수강인원보다 신청인원이 적을 경우를 대비하여,
	// min(k(수강 가능 인원), (int)vec.size()(신청인원))을 사용함
	
	// vec.size()는 size_t 값을 반환하기에 int 변환해주어야 함
	for (int i = 0; i < min(k, (int)vec.size()); i++)
		cout << vec[i].first << '\n';

	return 0;
}