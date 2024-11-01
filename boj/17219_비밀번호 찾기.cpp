#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    map<string, string> mp;
    cin >> n >> m;

    while (n--) {
        string k, v;
        cin >> k >> v;
        mp[k] = v;
    }
    vector<string> vec;
    for(int i = 0; i < m; i++){
        string p;
        cin >> p;
        vec.push_back(p);
    }

    for(string str : vec)
        cout << mp[str] << '\n';

    return 0;
}