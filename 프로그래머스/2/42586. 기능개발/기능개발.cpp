#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> pr, vector<int> sp) {
    vector<int> answer;
    
    int s = pr.size();
    vector<int> day(s);
    
    while(true) {
        bool isAllFinish = true;
        for(int i = 0; i < s; i++) {
            if(pr[i] >= 100)
                continue;
            isAllFinish = false;
            pr[i] += sp[i];
            day[i]++;
        }
        if(isAllFinish) break;
    }
    for(int i = 1; i < s; i++) {
      if(day[i - 1] >= day[i])
          day[i] = day[i - 1];
    }
    for(int n : day)
        cout << n << '\t';
    queue<int> q;
    q.push(day[0]);
    for(int i = 1; i < s; i++) {
        if(q.empty())
            q.push(day[i]);
            
        int n = q.front();        
        
        if(n >= day[i])
            q.push(day[i]);
        else {
            answer.push_back(q.size());
            while(!q.empty()) 
                q.pop();
            q.push(day[i]);
        }
    }
    if(!q.empty())
        answer.push_back(q.size());        
    
    return answer;
}