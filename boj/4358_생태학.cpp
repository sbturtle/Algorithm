#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	map<string, int> m;
	string str;
	int c = 0;
	while (getline(cin, str, '\n')) {
		m[str]++;
		c++;
	}
	for (auto tr : m) {
		double p = ((double)tr.second / (double)c) * 100;
		printf("%s %.4f\n", tr.first.c_str(),p);
	}
	return 0;
}