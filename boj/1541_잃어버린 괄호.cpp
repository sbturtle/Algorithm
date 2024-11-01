#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> Split(string str, char ch) {
	int cur = 0;
	vector<string> vec;
	while (cur < str.length()) {
		int nxt = str.find(ch, cur);
		nxt = (nxt == -1) ? str.length() : nxt;
		string sp = str.substr(cur, nxt- cur);
		vec.push_back(sp);
		cur += sp.length() + 1;
	}
	return vec;
}

int Sum(string str) {
	vector<string> num = Split(str, '+');
	int sum = 0;
	for (string n : num)
		sum += stoi(n);

	return sum;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;	cin >> str;
	vector<string> vec = Split(str, '-');
	int result = Sum(vec[0]);

	for (int i = 1; i < vec.size(); i++)	
		result -= Sum(vec[i]);
	
	 cout << result;
	return 0;
}