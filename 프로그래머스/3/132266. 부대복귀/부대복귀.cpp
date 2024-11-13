#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> isvis(n + 1, -1);
    vector<int> answer;
    
    map<int,vector<int>> mp;
    
    for(auto r : roads) {
        mp[r[0]].push_back(r[1]);
        mp[r[1]].push_back(r[0]);
    }
    queue<int> q;
    
    q.push(destination);    
    isvis[destination] = 0;
    
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(int r : mp[cur]) {
            if(isvis[r] != -1)
                continue;
            isvis[r] = isvis[cur] + 1;
            q.push(r);
        }        
    }
    
    for(int s : sources)
        answer.push_back(isvis[s]);
    
    return answer;
}