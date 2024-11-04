#include <vector>
#include <queue>
#include <cmath>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq(works.begin(), works.end());
    while(n--){
        int t = pq.top();
        if(!t)
            break;
        pq.pop();        
        pq.push(--t);
    }
    while(!pq.empty()){
        int t = pq.top(); pq.pop();
        answer += pow(t,2);
    }
    
    return answer;
}